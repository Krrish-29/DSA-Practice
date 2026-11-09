// 4098. Minimize the Maximum Value of GCD-Connected Array
class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        // the problem requires numbers to be in increasing order
        // and adjacent numbers gcd be > 1 meaning two numbers cannot be same and need to have some number common 
        // in between them
        // for minimizing the last value of the array we have to minimize the increments in numbers 
        // while maintaining the gcd condition so we need to add minimum factor possible in numbers ahead
        // starting with given value, if its even then the minimum factor will be 2 (that will be added to all numbers till last) (any two even numbers will have gcd 2 including the number 2 itself) (and adding two will keep the numbers as even and maintain gcd at 2 which is the minimum we can do)
        // for odd there can be two cases either the number is prime or has some factor 
        // for non prime case we can still add the minimum factor to the next number keeping gcd condition true
        // cause the gcd of both numbers will have the minimumFactor (for reference consider the multiplication table of minimumFactor number, x * n => n x , nx + x => (n+1) x , both have gcd of x) 
        // and since the factor will be odd(else the number would have been even already), adding two odd will give even and then the problem transform into even case and we can add 2 for all the rest of numbers
        // for prime case there will be only one factor the number itself and since except 2 all primes are odd
        // and adding two odd will give even the problem again transforms into even case
        // the last number can be easily calculated using Arithmetic progression

        // the main edge case is also check if the array can exists irrespective of the last numbers value 
        // since the condition applied to numbers after index + 1 will need to applied to number before index - 1
        // and find we can safely find array[0], for that the working will be same by subtracting minimum factor
        // cause having headroom is better
        // and every fact above is true for add and subtract as well
        if(value % 2 == 0){
            if( value - 2*(index) > 1) return value + 2*1LL*(n - index - 1);
            return -1;
        }
        int minimumFactor = -1;
        int sqrtVal = sqrt(value);
        for(int i = 2;i <= sqrtVal;i++){
            if(value % i == 0) {
                minimumFactor = i;
                break;
            }
        }

        // prime number not at 0 meaning we cannot find the first value of array
        if(minimumFactor == -1 && index != 0) return -1; 

        if(minimumFactor == -1) minimumFactor = value; //making prime itself the minimum factor

        long long prevEven = value - minimumFactor, nextEven = value + minimumFactor;

        if(index == 0 && value == 1) return -1;

        if (prevEven - 2*(index - 1) > 1) {
            if(index == n-1) return value;
            return nextEven + 2*(n - index - 2);
        }
        return -1;
    }
};