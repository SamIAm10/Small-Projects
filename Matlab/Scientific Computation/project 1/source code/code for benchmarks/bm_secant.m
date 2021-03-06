clear; % clear all stored variables

% parameters for Bessel functions
a = 0.075;
b = 0.325;

% cutoff equation in f(x) = 0 form
syms x;
f = besselj(0, x*a)*bessely(0, x*b) - besselj(0, x*b)*bessely(0, x*a);
f_deriv = diff(f); % derivative of f(x)

n_max = 40;
tol = 0.0001;

first_initial_guess = zeros(100, 1);
second_initial_guess = zeros(100, 1);
number_of_iterations = zeros(100, 1);
solution = zeros(100, 1);
fail_or_success = strings([100, 1]);

% main algorithm loop
for i = 1:100
    x_0 = i;
    x_1 = i + 20;
    for n = 1:n_max
        f_0 = vpa(subs(f, x, x_0));
        f_1 = vpa(subs(f, x, x_1));
        slope = (f_1 - f_0)/(x_1 - x_0);
        x_2 = x_1 - f_1/slope;
        f_2 = vpa(subs(f, x, x_2));
        abs_error = abs(f_2);
        if abs_error < tol
            break
        end
        x_0 = x_1;
        x_1 = x_2; 
    end
    first_initial_guess(i) = i;
    second_initial_guess(i) = i + 20;
    number_of_iterations(i) = n;
    solution(i) = x_1;
    if n >= n_max || x_1 <= 0
        fail_or_success(i) = "F";
    else
        fail_or_success(i) = "S";
    end
end

data = table(first_initial_guess, second_initial_guess, number_of_iterations, solution, fail_or_success);
writetable(data, 'secant_data.xlsx')
