package models;

public class Contador {
    private int cont;

    public Contador(){
        this.cont = 0;
    }

    public synchronized void suma(){
        this.cont++;
    }
    public int getCont(){
        return this.cont;
    }
}
