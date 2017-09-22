
import java.net.Socket;
import java.util.LinkedList;

/**
 *
 * @author Leonardo
 */
public class Traffic {
    
    LinkedList<Car> traffic = new LinkedList<Car>();
    LinkedList<Socket> sockets = new LinkedList<Socket>();
    
    // carro que realiza o pedido é add ao trafego
    public void add(Car c, Socket s){
        traffic.add(c);
        sockets.add(s);
    }
    
    // verifica se o transito está vazio
    public boolean isEmpty(){
        return traffic.isEmpty();
    }
    
    // libera o primeiro carro para atravessar o cruzamento
    public void freeFirst(){
        traffic.getFirst().passing = true;
    }
    
    // retira o primeiro carro do trafego
    public void pop(){
        traffic.removeFirst();
        sockets.removeFirst();
    }
    
    public Socket getFirst(){
        return sockets.getFirst();
    }
    
}
