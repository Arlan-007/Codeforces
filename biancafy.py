import re
import sys
from pathlib import Path

NAMES = (
    "bianca",
    "bbianca",
    "biancaa",
    "bbiancaa",
    "binaca",
    "bbinaca",
    "binacaa",
    "bbinacaa",
)

TOKEN_PATTERN = re.compile(
    r'//[^\n]*'
    r'|/\*[\s\S]*?\*/'
    r'|R"[^ (]{0,16}\([\s\S]*?\)[^ "]{0,16}"'
    r'|"(?:\\.|[^"\\])*"'
    r"|'(?:\\.|[^'\\])*'"
    r'|\b[A-Za-z_]\w*\b'
)


def change_name(index):
    base = NAMES[index % len(NAMES)]
    case_pattern = index // len(NAMES)
    return "".join(
        letter.upper() if case_pattern & (1 << position) else letter
        for position, letter in enumerate(base)
    )


def biancafy(source):
    to_bianca = {}
    used = set()

    def replace(match):
        token = match.group()

        # Keep comments and literals unchanged.
        if token.startswith(("//", "/*", '"', "'", 'R"')):
            return token

        if token not in to_bianca:
            index = len(to_bianca)
            name = change_name(index)
            while name in used or name.lower() in to_bianca:
                index += 1
                name = name(index)
            to_bianca[token] = name
            used.add(name)

        return to_bianca[token]

    lines = []
    for line in source.splitlines(keepends=True):
        if line.lstrip().startswith("#"):
            lines.append(line)
        else:
            lines.append(TOKEN_PATTERN.sub(replace, line))

    aliases = "".join(
        f"#define {bianca} {original}\n"
        for original, bianca in to_bianca.items()
    )
    return aliases + "".join(lines)


def main():
    if len(sys.argv) != 2:
        print("Usage: python3 biancafy.py <input.cpp>")
        return 1

    input_path = Path(sys.argv[1])
    output_path = input_path.with_name(f"{input_path.stem}-biancafy{input_path.suffix}")

    source = input_path.read_text()
    output_path.write_text(biancafy(source))
    print(f"Wrote {output_path}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
