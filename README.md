# CPP 05: Burócratas 🏛️

Este módulo de C++ se centra en clases, herencia, polimorfismo y manejo de excepciones, usando un escenario de burócratas y formularios para practicar OOP.

---

## EX00 – Bureaucrat

**Clase Bureaucrat**: representa un burócrata con un nombre constante y un grado (1 = más alto, 150 = más bajo).

### Excepciones
- Objetos que contienen información sobre errores
- Se implementan como clases internas que heredan de `std::exception`

### Manejo de errores
- `try` → bloque donde puede ocurrir un error
- `throw` → lanza una excepción
- `catch` → atrapa y maneja la excepción

### Regla de rangos
Un número menor = rango más alto. 

**Ejemplo**: si un burócrata tiene grado 3 y lo asciendes, pasa a 2.

```cpp
class GradeTooHighException : public std::exception
{
    const char *what() const throw();
};
```

- `what() const throw()` → devuelve un mensaje de error sin modificar el objeto y sin lanzar otra excepción
- `catch(std::exception &e)` → atrapa cualquier excepción que herede de `std::exception`

| Palabra clave | Función | Motivo práctico |
|---------------|---------|-----------------|
| `virtual` | Polimorfismo dinámico | Permite que `what()` devuelva el mensaje correcto según la excepción |
| `public` | Acceso desde fuera de la clase | Garantiza que `e.what()` siempre funcione |

---

## EX01 – Form

**Clase Form**: representa un formulario que un burócrata puede firmar.

### Atributos
- `name` (constante)
- `isSigned` (booleano)
- `gradeToSign` (constante)
- `gradeToExecute` (constante)

### Métodos
- `beSigned(Bureaucrat const &b)` → firma el formulario si el burócrata tiene rango suficiente, sino lanza `GradeTooLowException`

### Regla de const
Solo se pueden asignar miembros no `const` en el operador `=`; los `const` solo se inicializan en el constructor.

---

## EX02 – AForm y formularios concretos

### Clase base: AForm (abstracta)
- Al menos una función virtual pura
- **Atributos privados**:
  - `target` → objetivo del formulario
  - `name`, `isSigned`, `gradeToSign`, `gradeToExecute`

### Métodos
- `beSigned(Bureaucrat const &b)` → firma el formulario si el burócrata cumple el rango
- `execute(Bureaucrat const &executor) const` → ejecuta el formulario si está firmado y el executor tiene rango suficiente

### Clases derivadas

| Clase | Acción | Grado sign | Grado exec |
|-------|--------|------------|------------|
| **ShrubberyCreationForm** | Crea `<target>_shrubbery` con árboles ASCII | 145 | 137 |
| **RobotomyRequestForm** | Robotomiza al target 50% de las veces | 72 | 45 |
| **PresidentialPardonForm** | Informa que el target fue perdonado | 25 | 5 |

### Notas
- Cada clase implementa `execute()` llamando a la lógica base primero
- **Bureaucrat**:
  - `executeForm(AForm const &form)` → intenta ejecutar el formulario y muestra éxito o error
- Si una clase derivada no tiene constructor por defecto, hay que llamar explícitamente al constructor de la base

---

## EX03 – Intern

**Clase Intern**: fábrica de formularios para no sobrecargar a los burócratas.

### Método principal
`makeForm(string formName, string target)`
- Crea dinámicamente un formulario que el Intern "conoce" (`new`) y devuelve un puntero a `AForm`
- Si el formulario no existe → imprime mensaje de error y devuelve `NULL`

### Ejemplo de uso

```cpp
Intern someRandomIntern;
AForm* rrf;

rrf = someRandomIntern.makeForm("robotomy request", "Bender");
```