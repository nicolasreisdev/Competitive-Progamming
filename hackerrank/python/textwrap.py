
import textwrap

def wrap(string, max_width):
    return textwrap.shorten(string, width=max_width, placeholder="\n")

if __name__ == '__main__':
    string, max_width = input(), int(input())
    result = wrap(string, max_width)
    print(result)