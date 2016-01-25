function setPhonemes()
{
	var xmlhttp, text;																						
	xmlhttp = new XMLHttpRequest();																		
	xmlhttp.open('GET', 'library.txt', false);																
	xmlhttp.send();																							
	text = xmlhttp.responseText;																			
																											
	var linesList = text.split(/\s\s|\n/);																	
	var size = linesList.length;																			
																											
	var ll_i;																								
	var wl_i = 0;																							
	var pl_i = 0;																							
																											
	for(ll_i = 0 ; ll_i < size ; ll_i++)																	
	{																										
		if(ll_i % 2 == 0)																					
			wordList[wl_i++] = linesList[ll_i];																
		else																								
			phonemeList[pl_i++] = linesList[ll_i];																
	}										
	
	text = "";																								
	linesList = "";
}