#include "main.h"

#define EI_NIDENT 16

/**
 * struct Elf64_Ehdr - ELF header structure
 * @e_ident: ELF identification bytes
 * @e_type: object file type
 * @e_machine: required architecture
 * @e_version: object file version
 * @e_entry: entry point virtual address
 * @e_phoff: program header table file offset
 * @e_shoff: section header table file offset
 * @e_flags: processor-specific flags
 * @e_ehsize: ELF header size in bytes
 * @e_phentsize: program header table entry size
 * @e_phnum: program header table entry count
 * @e_shentsize: section header table entry size
 * @e_shnum: section header table entry count
 * @e_shstrndx: section header table index of string table
 */
typedef struct {
    unsigned char e_ident[EI_NIDENT];
    uint16_t e_type;
    uint16_t e_machine;
    uint32_t e_version;
    uint64_t e_entry;
    uint64_t e_phoff;
    uint64_t e_shoff;
    uint32_t e_flags;
    uint16_t e_ehsize;
    uint16_t e_phentsize;
    uint16_t e_phnum;
    uint16_t e_shentsize;
    uint16_t e_shnum;
    uint16_t e_shstrndx;
} Elf64_Ehdr;

/**
 * display_elf_header - Display the information contained in the ELF header
 * @header: Pointer to the ELF header structure
 */
void display_elf_header(const Elf64_Ehdr *header)
{
	int i;

	printf("Magic:   ");
    for (i = 0; i < EI_NIDENT; i++)
    {
        printf("%02x ", header->e_ident[i]);
    }
    printf("\n");

    printf("Class:                             %s\n",
           (header->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
    printf("Data:                              %s\n",
           (header->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little endian" :
           (header->e_ident[EI_DATA] == ELFDATA2MSB) ? "2's complement, big endian" :
           "Unknown data format");
    printf("Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
    printf("OS/ABI:                            %d\n", header->e_ident[EI_OSABI]);
    printf("ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
    printf("Type:                              %d\n", header->e_type);
    printf("Entry point address:               0x%lx\n", (unsigned long)header->e_entry);
}

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	const char *filename;
    	int fd;
    	Elf64_Ehdr header;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    filename = argv[1];
    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        exit(98);
    }

    ssize_t bytes_read = read(fd, &header, sizeof(Elf64_Ehdr));
    if (bytes_read != sizeof(Elf64_Ehdr))
    {
        fprintf(stderr, "Error: Could not read ELF header\n");
        close(fd);
        exit(98);
    }

    display_elf_header(&header);

    close(fd);
    return (0);
}

