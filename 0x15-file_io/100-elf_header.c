#include "main.h"

#define ELF_HEADER_SIZE 64

/**
 * error_exit - Prints error message to stderr and exits with failure status
 * @msg: The error message to display
 *
 * Description: This function prints an error message to stderr and
 *              exits the program with a failure status code (98).
 */
void error_exit(char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/**
 * display_elf_header - Displays the information in the ELF header
 * @header: Pointer to the ELF header structure
 *
 * Description: This function displays the information contained in the
 *              ELF header structure to the standard output.
 */
void display_elf_header(const Elf64_Ehdr *header)
{
	int i;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%2.2x ", header->e_ident[i]);
	printf("\n");
	printf("  Class:                             ");
	switch (header->e_ident[EI_CLASS])
	{
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown>\n");
		break;
	}
	printf("  Data:                              ");
	switch (header->e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown>\n");
		break;
	}
	printf("  Version:                           %d (current)\n",
	       header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            ");
	switch (header->e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("Tru64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone/embedded system\n");
		break;
	default:
		printf("<unknown: %2.2x>\n", header->e_ident[EI_OSABI]);
		break;
	}
	printf("  ABI Version:                       %d\n",
	       header->e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	switch (header->e_type)
	{
	case ET_NONE:
		printf("NONE (No file type)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown>\n");
		break;
	}
	printf("  Entry point address:               %#lx\n",
	       (unsigned long)header->e_entry);
}

/**
 * main - Entry point
 * @argc: The argument count
 * @argv: The argument vector
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
		error_exit("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_exit("Error: Cannot open file");

	if (read(fd, &header, ELF_HEADER_SIZE) != ELF_HEADER_SIZE)
		error_exit("Error: Cannot read ELF header");

	display_elf_header(&header);

	if (close(fd) == -1)
		error_exit("Error: Cannot close file");

	return (0);
}

