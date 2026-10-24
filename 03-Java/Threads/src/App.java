import models.Contador;

public class App {
    public static void main(String[] args) throws Exception {
        Contador cuenta = new Contador();

        Thread proceso = new Thread(() -> {
            for(int i = 0; i < 100000; i++){
                cuenta.suma();
            }
        });
        Thread proceso2 = new Thread(() -> {
            for(int i = 0; i < 100000; i++){
                cuenta.suma();
            }
        });
        proceso.start();
        proceso2.start();
        
        try{
            proceso.join();
            proceso2.join();
        }catch(InterruptedException e){
            throw new RuntimeException(e);
        }

        System.out.println("El contador va por: " + cuenta.getCont());


    }
}
