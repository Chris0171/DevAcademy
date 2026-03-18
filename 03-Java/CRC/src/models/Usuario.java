package models;

// ! Responsabilidades:
// * Guardar información de un usuario
// * Solicitar prestamo de un libro. 
// * Devolver un libro prestado

// ! Colaboradores:
// * Bilbionteca: 
// * Prestamo:

public class Usuario {
  private String nombre;
  private String id;
  private int librosPrestados;

  public Usuario(String nombre, String id) {
    this.nombre = nombre;
    this.id = id;
    this.librosPrestados = 0; // Por defecto, el usuario no tiene libros prestados
  }

  public Usuario(String nombre, String id, int librosPrestados) {
    this.nombre = nombre;
    this.id = id;
    this.librosPrestados = librosPrestados;
  }

  public void solicitarPrestamo(int nLibros) {
    this.librosPrestados += nLibros;
  }

  public void devolverLibro(int nLibros) {
    this.librosPrestados -= nLibros;
  }
  // Getters y setters para nombre, id

  public String getNombre() {
    return nombre;
  }

  public String getId() {
    return id;
  }

  public int getLibrosPrestados() {
    return librosPrestados;
  }

  public void setLibrosPrestados(int librosPrestados) {
    this.librosPrestados = librosPrestados;
  }

}
