public class calculos {

    public static void main(String[] args) {
        double i=0;
        double Max= 10000000;
        double seno = 0, coseno = 0, tangente = 0, logaritmo = 0,raiz = 0;
        while (i<Max) {
            seno+= Math.sin(i);
            coseno+=Math.cos(i);
            tangente += Math.tan(i);
            logaritmo += Math.log10(i);
            raiz+= Math.sqrt(i);
            i++;
        }
    }
}