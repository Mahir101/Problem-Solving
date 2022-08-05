class Solution {
    public String convert(String s, int numRows) {
            int sz = s.length();
    
        ArrayList<ArrayList<Character>> adj = new ArrayList<ArrayList<Character>>(numRows);
        
        for(int i=0; i<numRows; i++)
            adj.add(new ArrayList<Character>());
        
        int shift = 0, setCounter = 0;
        
        if(numRows==1) {
            return s;
        }
        
        for(int i=0; i<sz; i++) {
            
            if(setCounter > 0) {
                adj.get(shift).add(s.charAt(i));
                shift--;
                setCounter--;
            } else {
                adj.get(shift).add(s.charAt(i));
                shift++;
                
                if(shift%numRows==0) {
                    setCounter = numRows-2;
                    shift = numRows-2; 
                }
            }
            
        } 
        
        String sb = "";
        for(ArrayList<Character> alc: adj) {
            for(Character ch: alc) {
                sb = sb.concat(ch.toString());
            }
        }
        
        return sb;
    }
}
