def assemble(fin: str, fout: str) -> None:
    pointers = {'_START': 0}

    file_in = open(fin, "r").read()

instructions = {
    'lda': (0, ("ram", "reg")),
    'sta': (1, ("reg", "ram")),
    'mov': (2, ("reg", "reg")),
    'add': (3, ("reg", "reg")),
    'sub': (4, ("reg", "reg")),
    'mul': (5, ("reg", "reg")),
    'div': (6, ("reg", "reg")),
    'out': (7, ("reg", "none")),
    'jmp': (8, ("ram", "none")),
    'jnz': (9, ("reg", "ram")),
    'stp': (10, ("none", "none"))
}

def cleanup(sin: str) -> str:
    ret = ""

    for i in range(len(sin)):
        if (str[i] == '\n'):
            pass

        a = str[i]

        for ia in range(len(a)):
            

if __name__ == "__main__":
    print("DO NOT DIRECT RUN ASSEMBLE.PY, RUN MAIN.PY INSTEAD")