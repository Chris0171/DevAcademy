import java.io.IOError;
import java.io.IOException;

public class App {
    public static void main(String[] args) throws Exception {
        // ? Tipos de errores según su naturaleza
        // * Errores de sintaxis -> Violaciones de las reglas del lenguaje.
        // * Errores semánticos -> Uso incorrecto de las instrucciones.
        // * Errores lógicos -> EL programa compila pero no cumple la especificación.

        // ? Errores según el momento en el que se detectan
        // * Errores de compilación -> Detectados por el compilador.
        // * Errores en tiempo de ejecución -> Se detectan durante la ejecución.

        // ? Gestión clásica de errores(códigos de retorno)
        /*
         * Antes de las excepciones(códigos modernos), los errores se
         * controlaban mediente códigos de retorno.
         */

        int resultado = dividir(10, 2);
        System.out.println(resultado);
        // ! Esto trae problemas
        // * Codigo poco legible.
        // * Mescla flujo normal con errores.
        // * Fácil olvidar manejar los errores.
        // * Aquí es donde entrar las excepciones, que son una forma más elegante de
        // * manejar los errores.

        // ? Concepto de excepciones
        /*
         * Una excepción es un evento(bloque de código) que interrumpe el flujo normal
         * de ejecución de un programa debido a una condición anormal o error que
         * ocurra.
         */
        /*
         * Ejemplos:
         * División por cero -> ArithmeticException
         * Índice fuera de rango -> ArrayIndexOutOfBoundsException
         * Error de entradad/salida -> IOException
         * Formatos numericos incorrectos -> NumberFormatException
         */
        // ? Modelos de erroes en java
        /*
         * Throwable -> Es la clase base para todas las excepciones y errores en Java.
         * Exception -> Es la clase base para todas las excepciones comprobadas.
         * Throwable
         * |--> Error -> Errores graves que no se pueden manejar.
         * |--> Exception -> Excepciones que se pueden manejar.
         */
        // ? Tratamiento de excepciones
        /*
         * try -> Bloque de código que se ejecuta y puede lanzar una excepción.
         * 
         * catch -> Bloque de código que recibe la excepción lanzada por el
         * bloque try y la maneja.
         * 
         * finally -> Bloque de código que se ejecuta siempre, independientemente
         * de si se lanzó un error o no. Normalmente se usa para liberar recursos.
         * 
         * throw -> Palabra clave que se usa para lanzar una excepción de forma
         * explícita.
         * 
         * throws -> Palabra clave que se usa en la declaración de un método para
         * indicar que el método puede lanzar una o más excepciones.
         */

        // ? Estructura básica de manejo de expeciones.
        /*
         * try {
         * // Código que puede lanzar un error o excepción.
         * } catch (Exception e){
         * System.out.println("Se ha producido un error: " + e.getMessage());
         * } finally {
         * // Código que se ejecuta simpre que se lance una expeción o no.
         * }
         */
        /*
         * 1- Se produce una exepción en el bloque try.
         * 2- Se busca el bloque catch compatible.
         * 3- Si se encuentra ese catch compatible, se ejecuta el código dentro
         * del bloque catch.
         * 4- Si no se encuentra un bloque catch compatible, la excepción se propaga.
         * 5- Una vez ejecutado el bloque catch, se ejecuta el bloque finally.
         */

        // ? Lanzar excepciones(throw)
        // * Se usa cuando queremos generar una excepción manualmente.
        // * throw new Exception("Mensaje de error");

        // * Cuando se usa ?
        // * Cuando se detecta una condición anormal
        // * Cuando queremos propagar un error a un nivel superior.

        // ? Manejadores (catch)
        // * Deben colocarse de más específico a más general.
        // * El orden es importante.

        // ! Ejemplo de orden incorrecto:
        // * catch (Exception e)
        // * catch (ArithmeticException e)

        // * Ejemplo de orden correcto:
        // * catch (ArithmeticException e)
        // * catch (Exception e)

        // ? Declaración de excepciones (throws)
        // * Se usa para indicar que un método puede lanzar una o más excepciones.
        // * Y propagar la responsaiblidad a un nivel superior.
        // * Ejemplo: public void miMetodo() throws IOException, SQLException
        // * Se debe de tener dentro de la función un throw new Exception("Mensaje de
        // * error")
        // * para lanzar la excepción.

        // ? Bloque finally
        // * Siempre se ejecuta.
        // * Es ideal para liberar recursos como cerrar archivos, cerrar
        // * conexiones a bases de datos, cerrar scanners, etc.
        // * Se ejecuta incluso si hay una excepción.

        int a = 10;
        int b = 0;
        int resultado2 = 0;
        try {
            resultado2 = a / b; // * Esto lanzará una ArithmeticException
        } catch (NumberFormatException e) {
            System.out.println("Error de formato numérico: " + e.getMessage());
        } catch (ArithmeticException e) {
            System.out.println("No se puede dividir por cero.");
            System.out.println("Se tomara el valor 2 como divisor por defecto.");
            resultado2 = a / 2;
        } finally {
            System.out.println("El resultado es: " + resultado2);
        }
    }

    public static int dividir(int a, int b) {
        if (b == 0) {
            return -1;
        } else {
            return a / b;
        }
    }
}
