# ICG Paing

Первая задача из курса "Инженерная и компьютерная графика"

<a href="/assets/task.pdf">Условия заkkдачи</a>

## Сборка

### Необходимо для сборки

- cmake 3.19+
- clang 19.1.7

### Зависимости для сборки

- Qt6.5+

### Собрать

```bash
cmake -S . -B build
cmake --build build --parallel 8
```

### Запустить

```bash
./build/icg_paint
```

# TODO

- [ ] исправить resize
- [ ] исправить reset
- [ ] оптимизация заливки
