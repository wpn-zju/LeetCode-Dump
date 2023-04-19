class Solution {
    int[] flag;
    public boolean circularArrayLoop(int[] nums) {
        flag = new int[nums.length];
        for(int i = 0; i < nums.length; i++) {
        	if(flag[i] != 1) {
        		if(to(i,i,nums)) {
        			return true;
        		}
        	}
        }
        return false;
    }
    public boolean to(int index,int first,int[] nums) {  
        //System.out.println(index);
    	if(flag[index] == 1)
    		return false;
        
    	int i =index+nums[index];
        while(i<0){
            i+=nums.length;
        }
        i%=nums.length;
    	

    	if(nums[i]*nums[index]<0) {
    		return false;
    	}
        if(index == i){
            return false;
        }
    	if(i == first) {
    		return true;
    	}
        if(flag[i] == 2)
            return true;
        flag[index] = 2;
    	boolean p = to(i,first,nums);
        flag[index] = 1;        
        return p;
    }
}