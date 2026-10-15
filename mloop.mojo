from std.python import PythonObject
from std.python.bindings import PythonModuleBuilder
from std.os import abort
from std.time import perf_counter_ns


@export
def PyInit_mloop() abi("C") -> PythonObject:
    try:
        var builder = PythonModuleBuilder("mloop")
        builder.def_function[mojo_loop]("mojo_loop")
        return builder.finalize()
    except e:
        abort(String("Ошибка при создании модуля Mojo для Python:", e))


def mojo_loop():
    var start_ns = Float64(perf_counter_ns())
    for i in range(1_000_000_001):
        if i % 100_000_000 == 0:
            print(t"i = {i}")

    var elapsed = round((Float64(perf_counter_ns()) - start_ns) / 1_000_000, 2)
    print(t"Elapsed (Mojo): {elapsed} ms")
