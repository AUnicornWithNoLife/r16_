import assemble

def main() -> None:
    fin = input("FILE IN: ")
    fout = input("FILE OUT: ")

    assemble.assemble(fin, fout)
    
if __name__ == "__main__":
    main()