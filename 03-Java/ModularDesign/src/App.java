import java.util.Scanner;

public class App {

	/*
	 * Un programa que permita gestionar las de varios estudiantes
	 * El sistema debe permitir hacer los siguiente:
	 * - Pedir cuantos estudiantes hay
	 * - Pedir la nota de cada estudiante
	 * - Mostrar todas las notas
	 * - Calcular el promedio de las notas
	 * - Mostrar la nota más alta
	 * - Mostrar la nota más baja
	 */

	// * Cohesión: Que tan relacionadas están las funciones entre sí
	// * Cada función tenga una única responsabilidad
	// * No tener una función general que haga todo(Gestion de alumnos)

	// * Acoplamiento: Que tanto dependen los modulos o funciones entre sí
	// * Evitar que una función dependa de otra para funcionar
	// * Priorizacion de un bajo acoplamineto.

	public static void main(String[] args) throws Exception {
		gestionDeAlumnos();
	}

	public static void gestionDeAlumnos() {
		int nroEstudiantes = pedirNumeroDeEstudiantes();
		double[] notas = pedirNotas(nroEstudiantes);

		mostrarNotas(notas);

		double promedio = calcularPromedio(notas);

		System.out.println("El promedio de las notas es: " + promedio);

		notaMaxima(notas);

		notaMinima(notas);
	}

	// ? Funcion para pedir el número de estudiantes
	public static int pedirNumeroDeEstudiantes() {
		Scanner sc = new Scanner(System.in);
		System.out.print("Ingrese el número de estudiantes: ");
		int numeroEstudiantes = sc.nextInt();

		sc.nextLine(); // Limpiar el buffer del scanner
		return numeroEstudiantes;
	}

	// ? Funcion para pedir las notas de los estudiantes
	public static double[] pedirNotas(int numeroEstudiantes) {
		Scanner sc = new Scanner(System.in);

		double[] notas = new double[numeroEstudiantes];

		for (int i = 0; i < numeroEstudiantes; i++) {
			System.out.print("Teclee la nota de un estudiante:");
			notas[i] = sc.nextDouble();
		}
		return notas;
	}

	// ? Funcion para mostrar las notas de los estudiantes
	public static void mostrarNotas(double[] notas) {
		System.out.println("\nLas notas introducidas son: ");

		// * For each para mostrar las notas
		for (double nota : notas) {
			System.out.println(nota);
		}
	}

	// ? Funcion para calcular el promedio de las notas
	public static double calcularPromedio(double[] notas) {
		double suma = 0;
		double promedio = 0;

		for (double nota : notas) {
			suma += nota;
		}
		promedio = suma / notas.length; // la longitud del arreglo de notas

		return promedio;
	}

	public static void notaMaxima(double[] notas) {
		double notaMaxima = notas[0];

		for (double nota : notas) {
			if (nota > notaMaxima) {
				notaMaxima = nota;
			}
		}

		System.out.println("La nota más alta es: " + notaMaxima);
	}

	public static void notaMinima(double[] notas) {
		double notaMinima = notas[0];

		for (double nota : notas) {
			if (nota < notaMinima) {
				notaMinima = nota;
			}
		}

		System.out.println("La nota más baja es: " + notaMinima);
	}
}
