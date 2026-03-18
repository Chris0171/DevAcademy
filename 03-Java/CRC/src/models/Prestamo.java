package models;

// ! Responsabilidades:
// * Registrar un prestamo
// * Estado del prestamo
// * Registrar fecha de prestamo
// * Registrar devolución

// ! Colaboradores:
// * Bilblioteca: 
// * Usuario:
// * Libro:

public class Prestamo {
  private Usuario usuario;
  private Libro[] librosPrestados;
  private String fechaPrestamo;
  private String fechaDevolucion;
  private boolean devuelto;

  public Prestamo(Usuario usuario, String fechaPrestamo, int nLibros) {
    this.usuario = usuario;
    this.fechaPrestamo = fechaPrestamo;
    this.librosPrestados = new Libro[nLibros];
    this.devuelto = false;
  }

  public void agregarLibroPrestado(Libro libro) {
    for (int i = 0; i < this.librosPrestados.length; i++) {
      if (this.librosPrestados[i] == null) {
        this.librosPrestados[i] = libro;
        i = this.librosPrestados.length;
      }
    }
  }

  public void getEstadoPrestamo() {
    mostrarInformacion();
    if (this.devuelto == false) {
      System.out.println("Se ha realizado el prestamo el día: "
          + this.fechaPrestamo);
    } else {
      System.out.println("El prestamo ya ha sido devuelto el día: "
          + this.fechaDevolucion);
    }
  }

  private void mostrarInformacion() {
    // * Información del prestamo:
    System.out.println("USUARIO: " + this.usuario.getNombre());

    System.out.println("LIBROS PRESTADOS (" + this.librosPrestados.length + "): ");

    for (int i = 0; i < this.librosPrestados.length; i++) {
      System.out.println(this.librosPrestados[i].getTitulo() + " -"
          + this.librosPrestados[i].getAutor()); // * Odisea - Homero
    }
  }

  public void registrarDevolucion(String fechaDevolucion) {
    this.devuelto = true;
    this.fechaDevolucion = fechaDevolucion;
  }

}
