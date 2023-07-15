#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

#define BUFFER_SIZE 1024

void display_elf_header(Elf64_Ehdr *header);

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
	int file, read_bytes;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(2, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		dprintf(2, "Error: Cannot open file '%s'\n", argv[1]);
		exit(98);
	}

	read_bytes = read(file, &header, sizeof(header));
	if (read_bytes != sizeof(header))
	{
		dprintf(2, "Error: Cannot read from file '%s'\n", argv[1]);
		close(file);
		exit(98);
	}

	display_elf_header(&header);

	close(file);
	return 0;
}

/**
 * display_elf_header - Display ELF header information
 * @header: Pointer to the ELF header
 */
void display_elf_header(Elf64_Ehdr *header)
{
	int i;
	char *class_desc, *data_desc, *osabi_desc, *type_desc;

	printf("ELF Header:\n");

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");

	switch (header->e_ident[EI_CLASS])
	{
	case ELFCLASS32:
		class_desc = "ELF32";
		break;
	case ELFCLASS64:
		class_desc = "ELF64";
		break;
	default:
		class_desc = "Invalid class";
		break;
	}
	printf("  Class:                             %s\n", class_desc);

	switch (header->e_ident[EI_DATA])
	{
	case ELFDATA2LSB:
		data_desc = "2's complement, little endian";
		break;
	case ELFDATA2MSB:
		data_desc = "2's complement, big endian";
		break;
	default:
		data_desc = "Invalid data encoding";
		break;
	}
	printf("  Data:                              %s\n", data_desc);

	printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);

	switch (header->e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:
		osabi_desc = "UNIX - System V";
		break;
	case ELFOSABI_NETBSD:
		osabi_desc = "UNIX - NetBSD";
		break;
	case ELFOSABI_LINUX:
		osabi_desc = "UNIX - Linux";
		break;
	case ELFOSABI_SOLARIS:
		osabi_desc = "UNIX - Solaris";
		break;
	default:
		osabi_desc = "Other";
		break;
	}
	printf("  OS/ABI:                            %s\n", osabi_desc);

	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

	switch (header->e_type)
	{
	case ET_NONE:
		type_desc = "NONE (No file type)";
		break;
	case ET_REL:
		type_desc = "REL (Relocatable file)";
		break;
	case ET_EXEC:
		type_desc = "EXEC (Executable file)";
		break;
	case ET_DYN:
		type_desc = "DYN (Shared object file)";
		break;
	case ET_CORE:
		type_desc = "CORE (Core file)";
		break;
	default:
		type_desc = "Other";
		break;
	}
	printf("  Type:                              %s\n", type_desc);

	printf("  Entry point address:               0x%lx\n", (unsigned long)header->e_entry);
}
