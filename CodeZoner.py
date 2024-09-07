from sys import argv, exit



if len(argv) != 3:
    print("Usage: python sectios_formater.py section_name entire_line_length")
    exit(1)


section_name = f" {argv[1]} "
section_length = len(section_name)
required_length = int(argv[2]) 


if(required_length <= section_length):
    print("Error: Required length is too small.")
    exit(1)


decorator_length = ((required_length - section_length)) // 2
decorator = '*' * decorator_length


print(f"/{decorator}{section_name}{decorator}/")
print(f"/{'*' * (required_length) }/")