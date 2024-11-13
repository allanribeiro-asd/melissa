clc;
clear;
%close all;

graph = 9;

# Import data
if (graph == 1)
data0 = dlmread('0521/SH0/0.txt');
####################################
elseif(graph == 2)
  data0 = dlmread('0522/SH0/0.txt');
elseif(graph == 3)
  data0 = dlmread('0522/SH1/0.txt');
####################################
elseif(graph == 4)
  data0 = dlmread('0524/SH0/0.txt');
elseif(graph == 5)
  data0 = dlmread('0524/SH1/0.txt');
elseif(graph == 6)
  data0 = dlmread('0524/SH1/1.txt');
####################################
elseif(graph == 7)
  data0 = dlmread('0526/SH1/0.txt');
####################################
elseif(graph == 8)
  data0 = dlmread('0528/SH0/0.txt');
elseif(graph == 9)
  data0 = dlmread('0528/SH1/1.txt');
####################################
end

# Extract time
#time = data(:, 1)';

# Extract temperatures
temperature0 = data0(:, 1)';
%temperature0 = temperature0(1)*normalize(temperature0);

# Extract pressure
#pressure0 = data0(:, 2)';
#pressure0 = temperature0(1)*normalize(pressure0);

# Extract humidity
humidity0 = data0(:, 2)'-temperature0(1);
%humidity0 = humidity0(1)*normalize(humidity0); %normalizar
humidity0 = humidity0-(humidity0(1)-temperature0(1)); % deslocar


time0 = 1:length(data0);

# Plot it
figure;
#plot(time0, temperature0, 'r', pressure0, 'p');
plot(time0, temperature0, 'r', humidity0, 'b');
