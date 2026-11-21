# Cajero Automático (ATM) — Implementación en C++

Simulador de cajero automático por consola escrito en C++ como trabajo final para **Programación (SD1002)** en la **Institución Universitaria Pascual Bravo**[cite: 1]. El programa organiza las operaciones bancarias mediante funciones con paso de parámetros por valor, control de flujo iterativo (`do-while`) y selección múltiple (`switch`).

## Arquitectura y diseño del código

* **Espacio de nombres y E/S:** Utiliza `#include <iostream>` y `using namespace std;` para gestionar la entrada estándar (`cin`) y salida estándar (`cout`).
* **Declaración adelantada (prototipos):** Declara las firmas de funciones antes de `main()` para permitir su invocación desde el bloque principal sin importar su posición física en el archivo:
  * `void consultarSaldo(double saldo);`
  * `double retirarDinero(double saldo, double retiro);`
  * `double consignarDinero(double saldo, double consignacion);`
  * `void tipoCuenta();`
* **Estado y ciclo principal (`main`):**
  * Inicializa `saldo = 1000000` (`double`), junto con las variables `opcion` (`int`) y `dinero` (`double`).
  * Mantiene el ciclo de ejecución mediante `do { ... } while (opcion != 5);`, garantizando al menos una renderización del menú y finalizando únicamente cuando `opcion == 5`.
  * Enruta cada selección hacia su operación correspondiente mediante `switch (opcion)` con sentencias `break` y un bloque `default` para entradas numéricas fuera del rango `1–5`.

## Especificación de funciones y validaciones

| Función | Parámetros | Retorno | Comportamiento y reglas de validación |
| :--- | :--- | :--- | :--- |
| `consultarSaldo` | `double saldo` | `void` | Imprime por consola el saldo actual recibido como argumento. |
| `retirarDinero` | `double saldo`, `double retiro` | `double` | Valida `retiro <= 0` (*"Valor invalido."*) y `retiro > saldo` (*"Saldo insuficiente."*). Si es válido, resta `retiro` a `saldo` y retorna el nuevo saldo; en caso de error, retorna `saldo` sin modificaciones. |
| `consignarDinero` | `double saldo`, `double consignacion` | `double` | Valida `consignacion <= 0` (*"Valor invalido."*). Si es mayor que `0`, suma `consignacion` a `saldo` y retorna el saldo actualizado; si no, retorna `saldo` intacto. |
| `tipoCuenta` | Ninguno | `void` | Imprime en salida estándar el tipo de cuenta (`Ahorros`). |

> **Nota sobre paso de argumentos:** `retirarDinero` y `consignarDinero` reciben `saldo` por valor y retornan el nuevo monto (`double`), el cual reasigna la variable `saldo` en `main()` (`saldo = retirarDinero(...)` y `saldo = consignarDinero(...)`).

## Estructura del repositorio

* `programa.cpp` — Código fuente en C++.
* `README.md` — Documentación técnica del proyecto[cite: 1, 2].
* `.vscode/` — Archivos de configuración del entorno de trabajo en Visual Studio Code[cite: 1, 2].
* `programa.exe`, `programa.ilk`, `programa.obj`, `programa.pdb`, `vc140.pdb` — Binarios, objeto y símbolos de depuración generados por el toolchain MSVC en Windows[cite: 1, 2].

## Compilación y ejecución

### Compilación con MSVC (Windows)
```bash
cl /EHsc programa.cpp
programa.exe
