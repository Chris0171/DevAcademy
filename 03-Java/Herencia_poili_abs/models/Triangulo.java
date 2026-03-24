package models;

public class Triangulo extends Figura {
  // * Atributos
  private double cateto1;
  private double cateto2;
  private double hipotenusa;

  private double altura;

  // * Constructor
  public Triangulo(double cateto1, double cateto2, double hipotenusa, double altura) {
    super(3, "Triangulo");
    this.cateto1 = cateto1;
    this.cateto2 = cateto2;
    this.hipotenusa = hipotenusa;
    this.altura = altura;
  }

  public Triangulo(double cateto1, double cateto2, double altura) {
    super(3, "Triangulo");
    this.cateto1 = cateto1;
    this.cateto2 = cateto2;
    this.altura = altura;
  }

  // * Métodos
  @Override
  public double area() {
    return (cateto1 * altura) / 2;
  }

  @Override
  public double perimetro() {
    return cateto1 + cateto2 + hipotenusa;
  }

  public double calcularHipotenusa() {
    return Math.sqrt(Math.pow(cateto1, 2) + Math.pow(cateto2, 2));
  }

  public static double calcularAreaTR(double base, double altura) {
    return (base * altura) / 2;
  }

}
