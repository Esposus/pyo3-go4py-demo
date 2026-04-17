import time

from rloop import rust_loop # type: ignore
from gloop import goLoop # type: ignore


if __name__ == "__main__":
    # Rust версия
    print("=== Rust loop ===")
    print(rust_loop())

    # Go версия
    print("\n=== Go loop ===")
    print(goLoop())

    # Python версия
    print("\n=== Python loop ===")
    start = time.time()
    for i in range(1000_000_001):
        if i % 100_000_000 == 0:
            print(f"i = {i}")
    elapsed_py = time.time() - start
    print(f"Elapsed (Python): {elapsed_py:.2f} sec\n")
