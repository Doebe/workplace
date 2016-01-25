/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author maghi001
 */
public class DialugeAct extends HttpServlet {

       static int dialodActInt = 1; 
 static ArrayList getDialogActs(String sentence) 
{
	    ArrayList dialogActs = new ArrayList(); // List of the dialog acts
            Boolean none = true;
            sentence = sentence.toLowerCase();
            dialodActInt = 1;

			// Check if the sentence involves an interjection dialog act
            System.out.println('d');
             if (isInterjection(sentence))
            {
                dialogActs.add("Interjection");
                dialodActInt *= 2;
                none = false;
            }

			// Check if the sentence involves an negation dialog act
			if( isNegation( sentence ) )
            {
				dialogActs.add("Negation");
                dialodActInt *= 3;
                none = false;
            }

			// Check if the sentence involves an affirmation dialog act
			if( isAffirmation( sentence ) )
            {
				dialogActs.add( "Affirmation");
                dialodActInt *= 5;
                none = false;
            }

			// Check if the sentence involves an assumption dialog act
			if( isAssumption( sentence ) )
            {
				dialogActs.add( "Assumption");
                dialodActInt *= 7;
                none = false;
            }

			// Check if the sentence involves an obligation dialog act
			if( isObligation( sentence ) )
            {
				dialogActs.add( "Obligation");
                dialodActInt *= 11;
                none = false;
            }

			// Check if the sentence involves an contrast dialog act
			if( isContrast( sentence ) )
            {
				dialogActs.add( "Contrast");
                dialodActInt *= 13;
                none = false;
            }

			// Check if the sentence involves an inclusivity dialog act
			if( isInclusivity( sentence ) )
            {
				dialogActs.add( "Inclusivity");
                dialodActInt *= 17;
                none = false;
            }

			// Check if the sentence involves an intensification dialog act
			if( isIntensification( sentence ) )
            {
				dialogActs.add( "Intensification");
                dialodActInt *= 19;
                none = false;
            }

			// Check if the sentence involves an response-resuest dialog act
			if( isResponseRequest( sentence ) )
            {
				dialogActs.add( "ResponseRequest");
                dialodActInt *= 23;
                none = false;
            }

			// Check if the sentence involves an word-search dialog act
			if( isWordSearch( sentence ) )
            {
				dialogActs.add( "WordSearch");
                dialodActInt *= 29;
                none = false;
            }

			// Check if the sentence involves an question dialog act
           if (isQuestion(sentence))
           {
		dialogActs.add( "Question" );
                dialodActInt *= 31;
             none = false;
           }

            // Check if the sentence involves an question dialog act
            if (isGreeting(sentence))
            {
                dialogActs.add("Greeting");
                dialodActInt *= 37;
                none = false;
            }

            // If none of the above dialog acts are used
            if(none)
                dialogActs.add("None");

          return dialogActs;
	}

 public static int getDialogActsInt()
        {
            return dialodActInt;
        }
	public static Boolean isInterjection( String sentence )
		{
            return (sentence.contains("yes ") || sentence.contains("yeah ") || sentence.contains("no ") || sentence.contains("right") ||
                     sentence.contains("nope") || sentence.contains("well ") || sentence.contains("all-right") || sentence.contains("of-course"));
		}

		// Check if the sentence involves an negation dialog act by looking for the words which express this dialog act
		public static Boolean isNegation( String sentence )
		{
			return ( sentence.contains( "no " ) || sentence.contains( "nope" ) || sentence.contains( "not" ) ||
                     sentence.contains("nothing") || sentence.contains("cannot") || sentence.contains("n't") || sentence.contains("none "));
		}

		// Check if the sentence involves an affirmation dialog act by looking for the words which express this dialog act
		public static Boolean isAffirmation( String sentence )
		{
			return ( sentence.contains( "yes" ) || sentence.contains( "yeah" ) || sentence.contains( " do" ) || 
					 sentence.contains( " am " ) || sentence.contains( "have" ) || sentence.contains( " are" ) || 
					 sentence.contains( "does" ) || sentence.contains( " is" ) || sentence.contains( "has" ) || sentence.contains("right") ||
                     sentence.contains("true") || sentence.contains("ok") || sentence.contains("all-right") || sentence.contains("of-course"));
		}

		// Check if the sentence involves an assumption dialog act by looking for the words which express this dialog act
		public static Boolean isAssumption( String sentence )
		{
			return ( sentence.contains( "i-guess" ) || sentence.contains( "i-suppose" ) || sentence.contains( "i-think" ) ||
                     sentence.contains("i guess") || sentence.contains("i suppose") || sentence.contains("i think") ||
					 sentence.contains( "maybe" ) || sentence.contains( "perhaps" ) || sentence.contains( "could" ) ||
                     sentence.contains("probably") || sentence.contains("assume"));
		}

		// Check if the sentence involves an obligation dialog act by looking for the words which express this dialog act
		public static Boolean isObligation( String sentence )
		{
			return ( sentence.contains( "have-to" ) || sentence.contains( "has-to" ) || sentence.contains( "need-to" ) ||
                     sentence.contains("ought-to") || sentence.contains("should"));
		}

		// Check if the sentence involves an contrast dialog act by looking for the words which express this dialog act
		public static Boolean isContrast( String sentence )
		{
			return ( sentence.contains( "but" ) || sentence.contains( "however" ) || sentence.contains( "although" ) ||
                     sentence.contains("though") || sentence.contains("whereas") || sentence.contains("while"));
		}

		// Check if the sentence involves an inclusivity dialog act by looking for the words which express this dialog act
		public static Boolean isInclusivity( String sentence )
		{
			return ( sentence.contains( "every" ) || sentence.contains( "all" ) || sentence.contains( "whole" ) ||
					 sentence.contains( "several" ) || sentence.contains( "plenty" ) || sentence.contains( "full" ) );
		}

		// Check if the sentence involves an intensification dialog act by looking for the words which express this dialog act
		public static Boolean isIntensification( String sentence )
		{
			return ( sentence.contains( "really" ) || sentence.contains( "very" ) || sentence.contains( "quite" ) ||
                     sentence.contains("completely") || sentence.contains("wonderful") || sentence.contains("lot") || 
					 sentence.contains( "great" ) || sentence.contains( "absolutely" ) || sentence.contains( "gorgeous" ) ||
					 sentence.contains( "huge" ) || sentence.contains( "fantastic" ) ||
                     sentence.contains("amazing") || sentence.contains("important") || sentence.contains("much"));
		}

		// Check if the sentence involves an response-request dialog act by looking for the words which express this dialog act
		public static Boolean isResponseRequest( String sentence )
		{
			return ( sentence.contains( "you-know" ) );
		}

		// Check if the sentence involves an word-search dialog act by looking for the words which express this dialog act
		public static Boolean isWordSearch( String sentence )
		{
			return ( sentence.contains( "um" ) || sentence.contains( "uh" ) || sentence.contains( "well" ) ||
                     sentence.contains("mm") || sentence.contains("hm") || sentence.contains("like") || sentence.contains("kind-of") ||
                     sentence.contains("i-mean") || sentence.contains("hmm") || sentence.contains("you-know"));
		}

        // Check if the sentence involves an greeting dialog act by looking for the words which express this dialog act
        public static Boolean isGreeting(String sentence)
        {
            return (sentence.contains("hi ") || sentence.contains("hello") || sentence.contains("how are you") ||
                     sentence.contains("good morning") || sentence.contains("good afternoon") || sentence.contains("good evening") ||
                     sentence.contains("good night") || sentence.contains("how do you do") || sentence.contains("what's up") || sentence.contains("what is up") ||
                     sentence.contains("how is it going") || sentence.contains("how are you doing"));
            
        }
	public static Boolean isQuestion( String sentence )
		{
            return (sentence.startsWith("how much do") || sentence.startsWith("what do") || sentence.startsWith("when do") || sentence.startsWith("where do") ||
					 sentence.startsWith( "how do" ) || sentence.startsWith( "who do" ) || sentence.startsWith( "which do" ) || sentence.startsWith( "how often" ) ||
					 sentence.startsWith( "whom do" ) || sentence.startsWith( "whose" ) || sentence.startsWith( "why do" ) || sentence.startsWith( "how many" ) ||
                     sentence.startsWith("how much is") || sentence.startsWith("what is") || sentence.startsWith("when is") || sentence.startsWith("where is") ||
					 sentence.startsWith( "how is" ) || sentence.startsWith( "who is" ) || sentence.startsWith( "which is" ) ||
                     sentence.startsWith("how much was") || sentence.startsWith("what was") || sentence.startsWith("when was") || sentence.startsWith("where was") ||
					 sentence.startsWith( "how was" ) || sentence.startsWith( "who was" ) || sentence.startsWith( "which was" ) ||
                     sentence.startsWith("how much were") || sentence.startsWith("what were") || sentence.startsWith("when were") || sentence.startsWith("where were") ||
                     sentence.startsWith("how were") || sentence.startsWith("who were") || sentence.startsWith("which were") ||
                     sentence.startsWith("how much are") || sentence.startsWith("what are") || sentence.startsWith("when are") || sentence.startsWith("where are") ||
                     sentence.startsWith("how are") || sentence.startsWith("who are") || sentence.startsWith("which are") ||
					 sentence.startsWith("do") || sentence.startsWith("does") || sentence.startsWith("have") || sentence.startsWith("what else") ||
                     sentence.startsWith("had") || sentence.startsWith("has") || sentence.startsWith("is") ||
                     sentence.startsWith("are") || sentence.startsWith("am") ||
                     sentence.startsWith("how old"));
		}
	
    /**
     * Processes requests for both HTTP
     * <code>GET</code> and
     * <code>POST</code> methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
       
      
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP
     * <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
        throws ServletException, IOException {
     //   processRequest(request, response);
        String Dialuge= request.getParameter("dialuge").toString();
       //----------------------
           ArrayList S=getDialogActs(Dialuge);
       //--------------
       String Sr= S.toString();
       String Srt=Sr.replace("["," ");
       Srt=Srt.replace(","," ");
       Srt=Srt.replace("]"," ");
   //    String Srt1=Srt.replaceAll("[", " ");
  //    String Srt2=Srt1.replaceAll("]", " ");
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        try {
              
          
            out.println(Srt);
            
        } finally {            
            out.close();
        }
    }

    /**
     * Handles the HTTP
     * <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
         
        
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>
}
