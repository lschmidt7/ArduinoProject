import java.io.*;
import java.net.*;
import java.lang.*;

class ClientTera {
    public static void main(String argv[]) throws Exception  {
        String sentence = "ola";
        
        String modifiedSentence;
        BufferedReader inFromUser = new BufferedReader( new InputStreamReader(System.in));
        Socket clientSocket = new Socket("192.168.0.104", 8090);
          //   while(true) {
                 
        DataOutputStream outToServer = new DataOutputStream(clientSocket.getOutputStream());


        // send
     
       
        
        outToServer.writeBytes(sentence + '\0');

        
        
        // receive
        
   
        
  //      sentence = inFromUser.readLine();
        
      //  System.out.println("FROM SERVER: " + sentence);
        
     BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
 
        modifiedSentence = inFromServer.readLine();
        
      System.out.println("FROM SERVER: " + modifiedSentence);

        
              
       
       // }
       
        
       clientSocket.close();
    }
}



