import struct

def assemble(fin: str, fout: str) -> None:
    pointers = {'_START': 0}

    file_in = open(fin, "r").read()

    f_clean = cleanup(file_in)

    for i in range(len(f_clean)):
        if f_clean[i][0] == '_':
            pointers.update({f_clean[i].split(" ")[0]: i})

    ram = []

    for i in range(len(f_clean)):
        f_c_i = f_clean[i].split(" ")

        if (f_c_i[0][0] == "_"):
            f_c_i = f_c_i[1:len(f_c_i)]

        print(f_c_i)

        if (f_c_i[0] == "val"):
            ram.append(int(f_c_i[1], 16))
            ram.append(0)
            ram.append(0)

            continue

        instruct = instructions[f_c_i[0]]

        ram.append(instruct[0])

        if instruct[1][0] == "none":
            ram.append(0)
            ram.append(0)

            continue
        elif instruct[1][0] == "ram":
            if f_c_i[1][0] == '_':
                ram.append(pointers[f_c_i[1]] * 3)
            else:
                ram.append(int(f_c_i[1]))
        elif instruct[1][0] == "reg":
            ram.append(registers.index(f_c_i[1]))

        if instruct[1][1] == "none":
            ram.append(0)

            continue
        elif instruct[1][1] == "ram":
            if f_c_i[2][0] == '_':
                ram.append(pointers[f_c_i[2]] * 3)
            else:
                ram.append(int(f_c_i[2]))
        elif instruct[1][1] == "reg":
            ram.append(registers.index(f_c_i[2]))

    file_out = open(fout, "wb")

    for i in range(len(ram)):
        a = struct.pack("@B", ram[i])
        file_out.write(a)

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

registers = [
    "r0",
    "r1",
    "inr",
    "acu",
    "r0a",
    "r0b",
    "r1a",
    "r1b"
]

def cleanup(sin: str) -> str:
    tmp = sin.split('\n')

    for i in range(len(tmp)):
        tmp[i] = " ".join(tmp[i].split(" "))

    return tmp

def is_allowed(c) -> bool:
    if c.isalnum():
        return True

    if c == '_':
        return True
            

if __name__ == "__main__":
    print("DO NOT DIRECT RUN ASSEMBLE.PY, RUN MAIN.PY INSTEAD")