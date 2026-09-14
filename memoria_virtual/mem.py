#!/usr/bin/env python3

hex_value = input("Entrada pagemap (hex): ").strip()

value = int(hex_value, 16)

print(f"\nValor: 0x{value:016x}")
print(f"Binário: {value:064b}\n")

# Campos documentados do Linux pagemap
fields = {
    63: "Present — página está presente na RAM",
    62: "Swapped — página está em swap",
    61: "File/shared — página pertence a arquivo ou é shared-anonymous",
    56: "Exclusive — página está mapeada exclusivamente",
    55: "Soft-dirty — página foi marcada como soft-dirty",
    57: "UFFD write-protected",
    58: "Guard region",
}

for bit in range(63, -1, -1):
    state = (value >> bit) & 1

    if bit in fields:
        print(f"bit {bit:2d} = {state}  <- {fields[bit]}")
    else:
        print(f"bit {bit:2d} = {state}")

# PFN
pfn = value & ((1 << 55) - 1)

print("\n--- Interpretação ---")
print(f"Present : {(value >> 63) & 1}")
print(f"Swapped : {(value >> 62) & 1}")
print(f"File/shared : {(value >> 61) & 1}")
print(f"Exclusive : {(value >> 56) & 1}")
print(f"Soft-dirty : {(value >> 55) & 1}")
print(f"PFN : 0x{pfn:x}")
