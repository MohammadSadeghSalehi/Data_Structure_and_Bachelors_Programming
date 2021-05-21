import java.util.*;
import java.io.*;
import java.io.IOException;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import java.awt.Color;

public class TextExtractor

{
    private String imageAddres;
    private String mainText;
    private String text;
    private int charInt;
    public TextExtractor(String imageAddress)
    {
        imageAddres=imageAddress;
    }

    public void extract(String keyAddress,String saveAddress)
    {
        try
        {
        BufferedImage key = ImageIO.read(new File(keyAddress));
        BufferedImage inputImage = ImageIO.read(new File(imageAddres));
        text="";
        for (int x = 0; x <inputImage.getWidth() ; x++)
			{
				for (int y = 0; y < inputImage.getHeight(); y++)
				{
                        int rgb = key.getRGB(x, y);
                        
                        Color c = new Color(rgb);
                        int r = c.getRed();
                        int g = c.getGreen();
                        int b = c.getBlue();
                if (r==255)
                {
                   
                   int rgbb = inputImage.getRGB(x, y);
                        Color e = new Color(rgbb);
                        text+=e.getRed()%2;
                 
                }
                 else if (g==255)
                {
                 
                   int rgbb = inputImage.getRGB(x, y);
                        Color e = new Color(rgbb);
                        text+=e.getGreen()%2;
                    
                }
                 else if (b==255)
                {
                   
                   int rgbb = inputImage.getRGB(x, y);
                        Color e = new Color(rgbb);
                        text+=e.getBlue()%2;
                    
                }
                }
            }

               ArrayList<String> arr = new ArrayList<String>();
               int k =text.length();
               for (int i =0;i<(k/8);i++)
               {   
                  
                       arr.add(text.substring(0,8));
                       text=text.substring(8);
                  
               }
               arr.add(text);

              int convertCount=0;
              mainText="";
              int charInt =0;
               for(int j=0;j<arr.size();j++)
               {
               for(int i=(arr.get(j)).length()-1;i>=0;i--)
                     {
                          charInt += ((arr.get(j).charAt(i)-48)*(int)(Math.pow(2,convertCount)));
                          convertCount++;
                         
                     }
                     char finalc=(char)(charInt);
                     mainText+=finalc;
                     convertCount=0;
                     charInt = 0;
               }
                
                        PrintWriter out = new PrintWriter(new File(saveAddress));
                        out.println(mainText);
                        out.close();
  }
  catch(FileNotFoundException fex)
    {
        System.out.println("File not found!");
    }
    catch(Exception ex)
    {
        System.out.println(ex.getMessage());
    }
}

}