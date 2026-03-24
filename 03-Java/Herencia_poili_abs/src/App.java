import models.Figura;
import models.Triangulo;

public class App {
    public static void main(String[] args) throws Exception {
        // * Ejemplo de ligadura estática
        System.out.println(Triangulo.calcularAreaTR(4, 5));
        // * Ejemplo de ligadura dinámica
        Triangulo triangulo1 = new Triangulo(3, 4, 5, 5);
        System.out.println(triangulo1.area());

        // ? Resumen Corto:
        /*
         * - Herencia -> Cuando una clase (hija) hereda atibutos y métodos de otra clase
         * (padre).
         * - Clase abstracta -> no se instancia, define métodos obligatorios para las
         * clases hijas
         * - Polimorfismo -> capacidad de un objeto de tomar muchas formas, heredar
         * métodos de su padre y modificarlos a su gusto.
         * - Tipos de polimorfismo: Los sobreescritura (override) y los de sobrecarga.
         * - Polimorfismo de sobreescritura -> cuando una clase hija modifica un método
         * heredado de su padre.
         * - Polimorfismo de sobrecarga -> cuando una clase tiene varios métodos con el
         * mismo nombre pero diferentes parámetros.
         * - Principio de Liskov -> para que se cumpla el principio de Liskov, la clase
         * hija debe ser capaz de sustituir a la clase padre sin que el programa falle.
         * - Ligadura estática -> se resuelve en tiempoo de compilación, debe asociarse
         * al método de la clase.
         * - Ligadura dinámica -> se resuelve en tiempo de ejecución, el método que se
         * ejecuta depende del tipo de objeto que se esté utilizando.
         */
    }
}
