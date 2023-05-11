FROM kost13/cpp-gtest:latest
WORKDIR /home
RUN git clone https://github.com/Eksalnoryuu/GTestDevOpsClass.git
WORKDIR /home/GTestDevOpsClass
RUN git clone https://github.com/google/googletest.git
RUN mkdir build
WORKDIR /home/GTestDevOpsClass/build
RUN cmake ..
RUN make
CMD [./main]