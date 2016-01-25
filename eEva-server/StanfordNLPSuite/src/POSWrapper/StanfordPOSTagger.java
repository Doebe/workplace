package POSWrapper;

import java.io.*;
import javax.servlet.http.*;
import javax.servlet.*;
import java.util.List;

import edu.stanford.nlp.ling.Sentence;
import edu.stanford.nlp.ling.TaggedWord;
import edu.stanford.nlp.ling.HasWord;
import edu.stanford.nlp.tagger.maxent.MaxentTagger;
 
public class StanfordPOSTagger extends HttpServlet
{
    private MaxentTagger tagger = null;
    
    public void init() throws ServletException
    {
        tagger = new MaxentTagger("edu/stanford/nlp/models/pos-tagger/english-left3words/english-left3words-distsim.tagger");
    }
    
    public void doGet (HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException
    {
        String testString = req.getParameter("text");
        
        if (testString == null) return;
        
        String tSentence = tagger.tagString(testString);
        
        PrintWriter out = res.getWriter();
        
        out.println(tSentence);
        
        out.close();
    }
}
