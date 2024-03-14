import sys


def main():
    if len(sys.argv) != 3:
        print("Usage: python sectios_formater.py section_name entire_line_length")
        sys.exit(1)

    text = sys.argv[1]
    total_length = int(sys.argv[2])
    text_length = len(text)
    #######################################################################
    # Forcing the final total length to be even if it not even
    if text_length % 2 != 0:
        text_temp_holder = text.split(' ')
        text_temp_holder[1] = " " + text_temp_holder[1]

        text = ' '.join(text_temp_holder)
        print(text)

    else:
        pass
    #######################################################################
    # Subtract 4 for the spaces around the text (/**/)
    decorator_length = (total_length - text_length) // 2 - 4

    # If the total_length isn't enough to include the text and minimum decoration, raise an error
    if decorator_length < 1:
        raise ValueError(
            "Total length is too short to include the text and decorations.")

    # Build the decorator
    decorator = '*' * decorator_length

    # Construct the full string with the text centered
    full_string = f"/*{decorator} {text} {decorator}*/"

    # Adjust if total_length is odd to ensure the string length matches total_length
    if len(full_string) < total_length:
        full_string = full_string.replace('/', '*')
        full_string = f"/{full_string}"
        full_string += '/'

    return full_string


print(main())
print("/" + "*"*(int(sys.argv[2])-2) + "/")
