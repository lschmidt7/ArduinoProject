
import java.net.Socket;
import java.util.LinkedList;
import javax.swing.DefaultListModel;
import javax.swing.JList;
import javax.swing.ListModel;

/**
 *
 * @author Leonardo
 */
public class Traffic {
    
    LinkedList<Car> traffic = new LinkedList<Car>();
    LinkedList<Socket> sockets = new LinkedList<Socket>();
    
    JList carsInTraffic;
    DefaultListModel m = new DefaultListModel();
    
    public Traffic(JList carsInTraffic){
        this.carsInTraffic = carsInTraffic;
    }
    
    // carro que realiza o pedido é add ao trafego
    public void add(Car c, Socket s){
        traffic.add(c);
        sockets.add(s);
        m.addElement(c.ip);
        carsInTraffic.setModel(m);
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
        Car c = traffic.removeFirst();
        sockets.removeFirst();
        m.removeElement(c.ip);
        carsInTraffic.setModel(m);
    }
    
    public Socket getFirst(){
        return sockets.getFirst();
    }
    
}
