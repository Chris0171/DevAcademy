package models;

// ! Responsabilidades:
// * Guardar infomación de un libro
// * Indicar si el libro está disponible
// * Cambiar el estado de un libro a prestado o disponible

// ! Colaboradores:
// * Biblioteca: 
// * Prestamo:

public class Libro {
  private String titulo;
  private String autor;
  private boolean disponible;

  public Libro(String titulo, String autor) {
    this.titulo = titulo;
    this.autor = autor;
    this.disponible = true; // Por defecto, el libro está disponible
  }

  public boolean getDisponibilidad() {
    return disponible;
  }

  public void prestarLibro() {
    this.disponible = false;
  }

  public void devolverLibro() {
    this.disponible = true;
  }
  // Getters y setters para titulo y autor

  public String getTitulo() {
    return titulo;
  }

  public String getAutor() {
    return autor;
  }

}
