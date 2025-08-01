class Solution {
   	public List<List<Integer>> generate(int numRows) {
	   
		  List<List<Integer>> triangle = new ArrayList<>();
		  
		    if(numRows == 0)
		       return triangle;
		       
		    
		for(int i =1;i<=numRows;i++){
		List row = new ArrayList();
		for(int j =0;j<i;j++){
		if(j==0 || j==i-1){
		row.add(1);
		}else{
			row.add(triangle.get(i-2).get(j) + triangle.get(i-2).get(j-1));
		}
		}
		triangle.add(row);

		}
		    return triangle;
		
	}
}