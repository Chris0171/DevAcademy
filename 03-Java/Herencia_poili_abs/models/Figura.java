package models;

public abstract class Figura {
  // * Atributos
  private int lados;
  private String nombre;

  // * Constructor
  public Figura(int lados, String nombre) {
    this.lados = lados;
    this.nombre = nombre;
  }

  // * Métodos
  public abstract double area();

  public abstract double perimetro();

}
