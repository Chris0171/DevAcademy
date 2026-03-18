package models;

// ! Responsabilidades:
// * Gestionar lista de libros disponibles
// * Gestionar lista de usuarios registrados
// * Gestionar lista de prestamos realizados

// ! Colaboradores:
// * Libro:
// * Usuario:
// * Prestamo:

public class Biblioteca {
  private String nombreBliblioteca;
  private String direccion;

  private Libro[] librosDisponibles;
  private Usuario[] usuariosRegistrados;
  private Prestamo[] prestamosRealizados;

  public Biblioteca(String nombreBiblioteca, String direccion, int nLibros, int nUsuarios, int nPrestamos) {
    this.nombreBliblioteca = nombreBiblioteca;
    this.direccion = direccion;
    this.librosDisponibles = new Libro[nLibros];
    this.usuariosRegistrados = new Usuario[nUsuarios];
    this.prestamosRealizados = new Prestamo[nPrestamos];
  }

  public void agregarLibro(Libro libroNuevo) {
    for (int i = 0; i < this.librosDisponibles.length; i++) {
      if (this.librosDisponibles[i] == null) {
        this.librosDisponibles[i] = libroNuevo;
        i = this.librosDisponibles.length;
      }
    }
  }

  public void registrarUsuario(Usuario usuarioNuevo) {
    for (int i = 0; i < this.usuariosRegistrados.length; i++) {
      if (this.usuariosRegistrados[i] == null) {
        this.usuariosRegistrados[i] = usuarioNuevo;
        i = this.usuariosRegistrados.length;
      }
    }
  }

  public void registrarPrestamo(Prestamo prestamoNuevo) {
    for (int i = 0; i < this.prestamosRealizados.length; i++) {
      if (this.prestamosRealizados[i] == null) {
        this.prestamosRealizados[i] = prestamoNuevo;
        i = this.prestamosRealizados.length;
      }
    }
  }

  public void mostrarLibrosDisponibles() {
    System.out.println("LIBROS DISPONIBLES EN LA BIBLIOTECA: ");
    for (int i = 0; i < this.librosDisponibles.length; i++) {
      if (this.librosDisponibles[i] != null) {
        if (this.librosDisponibles[i].getDisponibilidad() == true) {
          System.out.println(this.librosDisponibles[i].getTitulo() + " -"
              + this.librosDisponibles[i].getAutor());
        }
      }
    }
  }
}
