import models.Biblioteca;
import models.Libro;
import models.Prestamo;
import models.Usuario;

public class App {

    /*
     * CRC: Identificar clases, responsabilidades y colaboraciones
     * Una biblioteca quiere implementar un sistema para gestionar
     * prestamos de libros.
     * - El sistema debe permitir lo siguiente:
     * 1. Registrar libros.
     * 2. Registrar usuarios.
     * 3. Registrar prestamos de libros
     * 4. Registrar fechas de prestamo
     * 5. Permitir devolver libros
     */
    public static void main(String[] args) throws Exception {
        System.out.println("¡Bienvenido al sistema de gestión de biblioteca!");
        Biblioteca biblioteca = new Biblioteca("Biblioteca Central",
                "Calle redentor, 24", 100, 50, 1000);

        Libro libro1 = new Libro("Odisea", "Homero");
        Libro libro2 = new Libro("La Iliada", "Homero");
        Libro libro3 = new Libro("La Eneida", "Virgilio");
        Libro libro4 = new Libro("La Divina Comedia", "Dante Alighieri");

        Usuario usuario1 = new Usuario("Juan Pérez", "12345");
        Usuario usuario2 = new Usuario("María Gómez", "67890");

        biblioteca.agregarLibro(libro1);
        biblioteca.agregarLibro(libro2);
        biblioteca.agregarLibro(libro3);
        biblioteca.agregarLibro(libro4);
        biblioteca.agregarLibro(new Libro("El Quijote", "Miguel de Cervantes"));

        biblioteca.registrarUsuario(usuario1);
        biblioteca.registrarUsuario(usuario2);

        biblioteca.mostrarLibrosDisponibles();

        Prestamo pres1 = new Prestamo(usuario1, "2026-03-18", 2);

        libro2.prestarLibro(); // * Prestamos el libro "La Iliada"
        libro3.prestarLibro(); // * Prestamos el libro "La Eneida"

        pres1.agregarLibroPrestado(libro2); // * Agregamos el libro "La Iliada" al prestamo
        pres1.agregarLibroPrestado(libro3); // * Agregamos el libro "La Eneida" al prestamo
        pres1.getEstadoPrestamo();

        biblioteca.registrarPrestamo(pres1);

        biblioteca.mostrarLibrosDisponibles();

        pres1.registrarDevolucion("2026-03-25");
        libro2.devolverLibro(); // * Devolvemos el libro "La Iliada"
        libro3.devolverLibro(); // * Devolvemos el libro "La Eneida"
        pres1.getEstadoPrestamo();

        biblioteca.mostrarLibrosDisponibles();
    }
}
