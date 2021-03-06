template <typename type>
class Array{
    public:

        virtual ndimensions category() = 0;

        virtual void create(Data dim) = 0;

        virtual Data getDim() = 0;

        /*
         * Función que coloca en null cada posicion de la matriz 
         */
        virtual void init() = 0;

        virtual void insert(Data pos, type value) = 0;

        virtual type extract(Data pos) = 0;

        virtual void destroy() = 0;

        virtual bool search(type value) = 0;

        virtual int count(type value) = 0;

        virtual void reverse()= 0;

        virtual void show(bool verbose) = 0;
};