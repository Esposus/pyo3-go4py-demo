# Python Native Extensions: Rust + Go

Этот проект демонстрирует, как вызвать высокопроизводительный код на **Rust** (через PyO3 + maturin) и **Go** (через go4py) из Python.  
Один и тот же цикл (1 миллиард итераций с выводом каждые 100 миллионов) выполняется на трёх языках, и вы можете сравнить производительность.

## 🚀 Результаты (на моей машине)

| Язык       | Время      |
|------------|------------|
| **Rust**   | ~0.78 сек  |
| **Go**     | ~0.74 сек  |
| **Python** | ~50.36 сек |

> Ускорение более чем в **60 раз** по сравнению с чистым Python.

### Склонируйте репозиторий
```bash
git clone git@github.com:Esposus/pyo3-go4py-demo.git
```

### Создайте виртуальное окружение
```bash
uv sync
```

### Активируйте виртуальное окружение
```bash
. .venv/bin/activate

```

### Соберите Rust-модуль
```bash
cd rloop
maturin develop --release
cd ..
```

### Собрерите Go-модуль
```bash
go4py build gloop
```
### Запустите сравнение
```bash
uv run python main.py
```


# Шпаргалка
```text
maturin new rloop
maturin develop --release
maturin build --release

go4py init gloop
go4py build gloop
```