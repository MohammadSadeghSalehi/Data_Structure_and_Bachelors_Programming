import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import java.awt.Color;

public class Main
{
	public static void main(String[] args)
    {
        try 
        {
        if(args.length<3)
        {
            throw new Exception("Number of arguments must be grater than 2!");
        }
        else if(args.length>4)
        {
            throw new Exception("Number of arguments must be lesser than 5!");
        }
        if(args[0].equals("-h"))
        {
        TextHider a = new TextHider(args[1]);
        if(args.length<4)
        {
        a.hide(args[2],""); 
        }
        else
        {
        a.hide(args[2],args[3]);
        }
        }
        else if(args[0].equals("-u"))
        {
        TextExtractor b = new TextExtractor(args[1]);
        if(args.length<4)
        {
        b.extract(args[2],"result.txt"); 
        }
        else
        {
        b.extract(args[2],args[3]+"\\result.txt");
        }
        }
        else
        {
        throw new Exception("Wrong argument format!");    
        }
        }
      
    catch(Exception ex)
    {
        System.out.println(ex.getMessage());
    }
    }
}


