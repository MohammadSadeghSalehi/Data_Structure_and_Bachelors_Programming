import java.util.*;
import java.io.*;
import java.io.IOException;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import javax.imageio.ImageIO;
import java.awt.Color;

public class TextHider
{
private String text;
private String textAddres;
private String binaryText;
private String binaryReversed;
private int red,green,blue;
private String strr,strg,strb;
public TextHider(String textAddress) 
{
    textAddres = textAddress;
}
public void hide (String imageAddress,String savingAddress )
{
    try
    {
    //start of converting text to binary
    Scanner in = new Scanner(new File(textAddres));
    binaryText="";
binaryReversed="";
strr="";strg="";strb="";
text="";
while(in.hasNextLine())
{
    text+=in.nextLine();
}
    for(int i = 0;i<text.length();i++)
    {   
        int ascii = text.charAt(i);
        for(int j = 0;j<8;j++)
        {
        binaryReversed+=ascii%2;ascii=ascii/2;
        }
        for(int k=7;k>=0;k--)
        {
        binaryText+=binaryReversed.charAt(k);
        }
        binaryReversed="";
    }
    //end of converting text to binary
    //start hiding

    BufferedImage inputImage = ImageIO.read(new File(imageAddress));
    if ((0.75)*(inputImage.getWidth()*inputImage.getHeight())<text.length()*8)
    {
        throw new Exception("You cannot hide your text in this image!You need more pixel and a bigger image");
    }
    
    int[][] pixelLocation = new int[inputImage.getWidth()][inputImage.getHeight()];
    for (int i=0;i<text.length()*8;i++)
    {
        pixelLocation[(int)(Math.random()*inputImage.getWidth()-1)][(int)(Math.random()*inputImage.getHeight()-1)]=1;
    }   
    int counter=0;
  
    for (int x = 0; x <inputImage.getWidth() ; x++)
			{
				for (int y = 0; y < inputImage.getHeight(); y++)
				{
					if(pixelLocation[x][y]==1)
                    {
                        int red=0,blue=0,green=0;
                        int rgb = inputImage.getRGB(x, y);
                        int n = (int)((Math.random()*3)+1);
                        Color c = new Color(rgb);
                   
                        if(n==1)
                        {
                          
                            int p = binaryText.charAt(counter)-48;
                            counter++;
                            
                             if(c.getRed()%2==0&&p==0)
                             {
                                 red=c.getRed();
                             }
                             else if(c.getRed()%2==0&&p==1)
                             {
                                 red=c.getRed()+1;
                             }
                             else if(c.getRed()%2==1&&p==0)
                             {
                                 red=c.getRed()-1;
                             }
                             else if(c.getRed()%2==1&&p==1)
                             {
                                 red=c.getRed();
                             }
                          
                        blue=c.getBlue();
                        
                        green=c.getGreen();   
                            pixelLocation[x][y]=2;
                        }
                        else if(n==2)
                        {
                            
                            int p = binaryText.charAt(counter)-48;
                            counter++;
                             
                         if(c.getGreen()%2==0&&p==0)
                             {
                                 green=c.getGreen();
                             }
                             else if(c.getGreen()%2==0&&p==1)
                             {
                                 green=c.getGreen()+1;
                             }
                             else if(c.getGreen()%2==1&&p==0)
                             {
                                 green=c.getGreen()-1;
                             }
                             else if(c.getGreen()%2==1&&p==1)
                             {
                                 green=c.getGreen();
                             }
                        red=c.getRed();
                        blue=c.getBlue();
                            pixelLocation[x][y]=3;
                        }
                        else if(n==3)
                        {
                            
                            int p = binaryText.charAt(counter)-48;
                            counter++;
                           
                         if(c.getBlue()%2==0&&p==0)
                             {
                                 blue=c.getBlue();
                             }
                             else if(c.getBlue()%2==0&&p==1)
                             {
                                 blue=c.getBlue()+1;
                             }
                             else if(c.getBlue()%2==1&&p==0)
                             {
                                 blue=c.getBlue()-1;
                             }
                             else if(c.getBlue()%2==1&&p==1)
                             {
                                 blue=c.getBlue();
                             }
                        red=c.getRed();
                        green=c.getGreen();
                            pixelLocation[x][y]=4;
                        }
                        
                    Color cFinal = new Color(red, green, blue);
                    int rgbFinal=cFinal.getRGB();
                   
                    inputImage.setRGB(x, y, rgbFinal);
                    }
                } 
            }
            //end of hiding
            //start making key
            
            	BufferedImage raw = new BufferedImage(inputImage.getWidth(), inputImage.getHeight(), BufferedImage.TYPE_INT_RGB);

            for (int x = 0; x < raw.getWidth(); x++)
			{
				for (int y = 0; y < raw.getHeight(); y++)
				{
                    int rgb = raw.getRGB(x, y);
                    Color f = new Color(rgb);
                    int red=0,blue=0,green=0;
					
                    if(pixelLocation[x][y]==2)
					{
                    red = 255;
                    }
                    else if(pixelLocation[x][y]==3)
					{
					green = 255;
                    }	
                    else if(pixelLocation[x][y]==4)
					{
                    blue = 255;
                    }
                    				
					Color key = new Color(red,green,blue);
					
					raw.setRGB(x, y, key.getRGB());
				}
			}
            if (savingAddress!="")
            {
ImageIO.write(raw, "BMP", new File(savingAddress+"\\key.bmp"));
ImageIO.write(inputImage, "BMP", new File(savingAddress+"\\hided.bmp"));
            }
            else
            {
              ImageIO.write(raw, "BMP", new File("key.bmp"));
              ImageIO.write(inputImage, "BMP", new File("hided.bmp"));  
            }

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