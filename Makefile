CC=g++
SOURCES=main.cpp

run: build
	@./main

build:
	@$(CC) $(SOURCES) -o main 

clean:
	@rm -rf *.o 


# // double newtonMethod(double a0, double b0, double eps) {
# //     double a = a0, b = b0;
# //     double prev_x = (-1)*pow(10,4);
# //     double current_x = a;
# //     while ( std::abs(prev_x - current_x) > eps ) {
# //         prev_x = current_x;
# //         current_x = newtonIter(prev_x);
# //         if (!(current_x >= a and current_x <= b)) {
# //             current_x = halfDivIter(a, b);
# //         }
# //         double c = f0(current_x);
# //         if (c > 0) {
# //             b = c;
# //         } else {
# //             a = c;
# //         }
# //         std::cout << current_x << '\n';        
# //     } 
# //     return current_x;
# // }