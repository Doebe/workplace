package SentimentWrapper;

import java.io.*;
import javax.servlet.http.*;
import javax.servlet.*;
import java.util.List;
import java.util.Properties;

import edu.stanford.nlp.pipeline.*;
import edu.stanford.nlp.sentiment.*;
import edu.stanford.nlp.util.*;
import edu.stanford.nlp.ling.*;
 
public class StanfordSentiment extends HttpServlet
{
    private Properties props;
    private StanfordCoreNLP pipeline;
    
    public void init() throws ServletException
    {
        props = new Properties();
        props.setProperty("annotators", "tokenize, ssplit, pos, lemma, parse, sentiment");
        
        pipeline = new StanfordCoreNLP(props);
    }
    
    public void doGet (HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException
    {
        String testString = req.getParameter("text");
        
        if (testString == null) return;
        
        
        
        Annotation annotation = pipeline.process(testString);
        List<CoreMap> sentences = annotation.get(CoreAnnotations.SentencesAnnotation.class);
        
        PrintWriter out = res.getWriter();
        
        for (CoreMap sentence : sentences)
        {
            String sentiment = sentence.get(SentimentCoreAnnotations.SentimentClass.class);
            out.println(sentiment + "\t" + sentence);
        }
        
        out.close();
    }
}
