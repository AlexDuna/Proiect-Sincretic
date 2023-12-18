FROM gcc:latest
WORKDIR C:\Users\Alex\Desktop\Proiect Sincretic\Proiect-Sincretic
COPY KnightTour.cpp .
RUN gcc -o KnightTour KnightTour.cpp -lstdc++
CMD ["./KnightTour"]