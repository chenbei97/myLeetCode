#include <iostream>
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;
/*
g++ -o ..\output\SparseMat -g SparseMat.cpp -std=c++20 -I C:/msys64/mingw64/include -I C:/msys64/mingw64/lib -l libopencv_calib3d452 -l libopencv_core452 -l libopencv_dnn452 -l libopencv_features2d452 -l libopencv_flann452 -l libopencv_gapi452 -l libopencv_highgui452 -l libopencv_imgcodecs452 -l libopencv_imgproc452 -l libopencv_ml452 -l libopencv_objdetect452 -l libopencv_photo452 -l libopencv_stitching452 -l libopencv_video452 -l libopencv_videoio452 
../output/SparseMat
*/
double cross_corr(const SparseMat& a, const SparseMat& b)
{
    const SparseMat *_a = &a, *_b = &b; // 获取指向引用a和b的指针
    // 如果b包含的元素比a少，那么迭代b会更快,所以交换
    if(_a->nzcount() > _b->nzcount())
        std::swap(_a, _b); // 交换指针比较高效,所以才事先获取指针
    // 获取_a的2个迭代器
    SparseMatConstIterator_<float> it = _a->begin<float>(),
                                   it_end = _a->end<float>();
    double ccorr = 0; // 计算的相关系数
    // 迭代_a
    for(; it != it_end; ++it)
    {
        // 从第一个矩阵中取下一个元素
        float avalue = *it; // 获取坐标节点的值
        const SparseMat::Node* anode = it.node(); // 获取迭代器指向的坐标点
        // 试着在第二个矩阵中找到一个索引相同的元素
        // 因为散列值只取决于元素索引,然后重用节点中存储的哈希值
        size_t* ptr = const_cast<size_t*>(&anode->hashval); // 去掉const限定
        float bvalue = _b->value<float>(anode->idx,ptr); // 因为value的hashval是非const类型的
        ccorr += avalue * bvalue; // 相关系数等于2个值的乘积且累加
    }
    return ccorr;
}
void print_matrix(const SparseMat* m) {
    SparseMatConstIterator_<float> it = m->begin<float>(); // 使用成员函数需要模板参数
    SparseMatConstIterator_<float> it_end = m->end<float>();
    for (; it != it_end; ++it) {
        const SparseMat::Node* n = it.node();
        cout << n->idx[0] << " " << n->idx[1] << " " << *it << endl;
    }
}
void calling_function1(void) {
        int ndim = 2;
        int size[] = { 3,3 };
        cv::SparseMat_<float> sm(ndim, size); // 使用模板类实例化,无需指定数据类型,float模板参数已告知
        print_matrix(&sm); // 调用第一种写法,这个函数必须指明模板类型
}
template<typename T> void print_matrix(const SparseMat_<T>* m) {
    SparseMatConstIterator_<T> it = m->begin(); // 无需模板参数
    SparseMatConstIterator_<T> it_end = m->end();
    while (it != it_end) {
        const typename SparseMat_<T>::Node* n = it.node(); // 注意要加typename说明符
        cout << n->idx[0] << " " << n->idx[1] << " " << *it << endl;
        ++it;
    }
}
void calling_function2(void) {
        int ndim = 2;
        int size[] = { 3,3 };
        cv::SparseMat sm(ndim, size, CV_32F); // 必须指定类型,因为没有模板参数
        print_matrix<float>((SparseMat_<float>*)&sm); // 调用第二种写法,这个函数不需要指明模板类型,且要强制转换为对应指针类型
}
int main(int argc,char**argv)
{
    /*
        Mat存储数据按照C风格的可以按照索引得到数据元素，SparseMat使用哈希表存储非0元素,适用于非0元素很少的矩阵
        SparseMat最大的区别就是访问元素的机制不同，可以使用4种方法访问
        即SparseMat::ptr()、SparseMat::ref<>()、SparseMat::value<>()和SparseMat::find<>()函数
        1、ptr方法,存在一些变体
            1.1、uchar* SparseMat::ptr(int i, bool createMissing,size_t * hashcal = 0); // 用于一维数组访问的
            参数：
                i：表示请求元素的索引
                createMissing：表示是否创建缺失元素，如果这个元素不存在于数组中，则创建一个缺失元素
                hashcal：表示哈希值，如果不需要计算哈希值，可以将其设置为0
            返回值：
                返回请求元素的指针
            1.2、uchar* SparseMat::ptr(int i, int j, bool createMissing,size_t * hashcal = 0); // 用于二维数组访问的
            1.3、uchar* SparseMat::ptr(int i, int j, int k, bool createMissing,size_t * hashcal = 0); // 用于三维数组访问的
            1.4、uchar* SparseMat::ptr(const int * idx, bool createMissing,size_t * hashcal = 0);
                参数：
                    idx：表示请求元素的索引数组,用于访问更多维的数组
                    createMissing：表示是否创建缺失元素，如果这个元素不存在于数组中，则创建一个缺失元素
                    hashcal：表示哈希值，如果不需要计算哈希值，可以将其设置为0
                返回值：
                    返回请求元素的指针
        2、ref<>()方法,返回一个指向数组中特定元素的引用,类似于ptr,也可以接受1,2,3个索引或者一个索引数组
            但ref是个模板函数,必须指定对象类型,默认CV_32F,也就是ref<>()使用的是CV_32F类型
            2.1、template<typename _Tp> _Tp& ref<_TP>(int i ,size_t * hashcal = 0 ); // 用于一维数组访问的
            2.2、template<typename _Tp> _Tp& ref<_TP>(int i ,int j,size_t * hashcal = 0 ); // 用于二维数组访问的
            2.3、template<typename _Tp> _Tp& ref<_TP>(int i ,int j,int k,size_t * hashcal = 0 ); // 用于三维数组访问的
            2.4、template<typename _Tp> _Tp& ref<_TP>(const int * idx,size_t * hashcal = 0 );// 用于多维数组访问的
        3、value<>()方法和ref<>()类似,但是返回的是值而非引用,也就是只读的
            多了2个变体,也就是基于SparseMat::Node*的变体
            3.1、template<typename _Tp> _Tp<> value<_TP>(int i ,size_t * hashcal = 0 ); // 用于一维数组访问的
            3.2、template<typename _Tp> _Tp value<_TP>(int i ,int j,size_t * hashcal = 0 ); // 用于二维数组访问的
            3.3、template<typename _Tp> _Tp value<_TP>(int i ,int j,int k,size_t * hashcal = 0 ); // 用于三维数组访问的
            3.4、template<typename _Tp> _Tp value<_TP>(const int * idx,size_t * hashcal = 0 );// 用于多维数组访问的
            3.5、template<typename _Tp> _Tp& value<_TP>(Node*n) ; // 使用Node*访问
            3.6、template<typename _Tp> const _Tp& value<_TP>(const Node*n) ; // 使用const Node*访问
        4、find<>(),返回指向元素的指针,但是基于模板实现不同于ptr
            find返回的是只读const指针,很多时候和ptr还是不能转换的
            4.1、template<typename _Tp> const _Tp* find<_TP>(int i ,size_t * hashcal = 0 ) const; // 用于一维数组访问的
            4.2、template<typename _Tp> const _Tp* find<_TP>(int i ,int j,size_t * hashcal = 0 ) const; // 用于二维数组访问的
            4.3、template<typename _Tp> const _Tp* find<_TP>(int i ,int j,int k,size_t * hashcal = 0 ) const; // 用于三维数组访问的
            4.4、template<typename _Tp> const _Tp* find<_TP>(const int * idx,size_t * hashcal = 0 ) const; // 用于多维数组访问的
        
        构造函数：
            SparseMat(int dims, const int* _sizes, int _type);
            SparseMat(const SparseMat& m);
            explicit SparseMat(const Mat& m);
            SparseMat& operator = (const SparseMat& m);
            SparseMat& operator = (const Mat& m);
        
        基本的成员函数(和Mat基本一致)：
            1、void copyTo( SparseMat& m ) const;
            2、void copyTo( Mat& m ) const;
            3、void convertTo( SparseMat& m, int r_type, double alpha = 1) const;
            4、void convertTo( Mat& m, int rtype, double alpha=1, double beta=0 ) const;
            5、void assignTo( SparseMat& m, int type=-1 ) const;
            6、void create(int dims, const int* _sizes, int _type);
            7、void release();
            8、void clear();
            9、void addref();
            10、size_t elemSize() const;
            11、size_t elemSize1() const;
            12、int type() const;
            13、int depth() const;
            14、int channels() const;
            15、int dims() const;
            16、const int* size() const;
            17、int size(int i) const;
        特有的成员函数：
            1、size_t nzcount() const;
            2、size_t hash(int i) const;
            3、size_t hash(int i, int j) const;
            4、size_t hash(int i, int j, int k) const;
            5、size_t hash(const int* idx) const;
            6、void erase(int i0, int i1, size_t* hashval=0);
            7、void erase(int i0, int i1, int i2, size_t* hashval=0);
            8、void erase(const int* idx, size_t* hashval=0);
            9、Node* node(size_t nidx);
            10、const Node* node(size_t nidx) const;
            11、uchar* newNode(const int* idx, size_t hashval);
            12、void removeNode(size_t hidx, size_t nidx, size_t previdx);
            13、void resizeHashTab(size_t newsize);
        属性：
            int flags;
            Hdr* hdr;
        关于迭代器的函数：
            1、SparseMatIterator begin();
            2、template<typename _Tp> SparseMatIterator_<_Tp> begin();
            3、SparseMatConstIterator begin() const;
            4、template<typename _Tp> SparseMatConstIterator_<_Tp> begin() const;
            5、SparseMatIterator end();
            6、template<typename _Tp> SparseMatIterator_<_Tp> end();
            7、SparseMatConstIterator end() const;
            8、template<typename _Tp> SparseMatConstIterator_<_Tp> end() const;
        
        关于Node: 
            它是一个迭代器可以获取的方法，是一个结构体，指向稀疏矩阵的实际数据区域，其定义如下：
            struct Node{
                size_t hashval; // 哈希值
                size_t next; // 指向下一个节点
                int idx[cv::CV_MAX_DIM]; // 指向对应元素的哈希值索引,int数组
            }

        关于Mat_和Mat,SparseMat_和SparseMat:
            后者实例化时不需要模板参数，前者需要模板参数
            但是前者在使用at参数时无需模板参数，后者必须模板参数
            举个例子：
                使用Mat实例化10×10的二维32位浮点数数组
                Mat m(10,10,CV_32F);
                如果这个m要访问元素,必须使用at的模板初始化，即
                m.at<Vec2f>(x,y) = cv::Vec2f(1.0f,2.0f);
                而模板类Mat_实例化需要模板参数，即
                Mat_<Vec2f> m(10,10);
                但是访问元素不需要模板参数，即
                m.at(x,y) = cv::Vec2f(1.0f,2.0f); // 或者
                m(x,y) = cv::Vec2f(1.0f,2.0f); 
            使用模板类实例化,后边使用成员函数就会极大的简化代码
            
            使用非模板类作为函数的参数传递时如果没有指定正确的类型可能会编译错误
            但是使用模板类配合typename就会更加的通用
            举个例子：
                // 一个只允许传递SparseMat的函数,如果输入的是CV_32F就会正确执行,但是其他类型就会报错
                void print_matrix(const SparseMat* m){
                    SparseMatConstIterator_<float> it = m->begin<float>(); // 使用成员函数需要模板参数
                    SparseMatConstIterator_<float> it_end = m->end<float>();
                    for(; it != it_end; ++it){
                        const SparseMat::Node* n = it.node();
                        cout << n->idx[0] << " " << n->idx[1] << " " << *it << endl;
                    }
                }
                // 改用模板类更加通用
                template<typename T> void print_matrix(const SparseMat_<T>* m){
                    SparseMatConstIterator_<T> it = m->begin(); // 无需模板参数
                    SparseMatConstIterator_<T> it_end = m->end();
                    while (it != it_end) {
                        const typename SparseMat_<T>::Node* n = it.node(); // 注意要加typename说明符
                        cout << n->idx[0] << " " << n->idx[1] << " " << *it << endl;
                        ++it;
                    }
                }
                // 这样调用第一种写法的函数可能要这样写
                void calling_function1(void){
                    ...
                    int ndim = 2;
                    int size[] = { 3,3 };
                    cv::SparseMat_<float> sm(ndim,size); // 使用模板类实例化,无需指定数据类型,float模板参数已告知
                    ...
                    print_matrix(&sm); // 调用第一种写法,直接调用无需模板参数
                }
                // 调用第二种写法的函数可能是这样
                void calling_function2(void){
                    ...
                    int ndim = 2;
                    int size[] = { 3,3 };
                    cv::SparseMat sm(ndim,size,CV_32F); // 必须指定类型,因为没有模板参数
                    ...
                    print_matrix<float>((SparseMat_<float>*)&sm); // 调用第二种写法,需要指明模板类型,且要强制转换为对应指针类型
                }
    */
    // 创建一个稀疏矩阵赋予初值SparseMat(int dims, const int* _sizes, int _type);
    // 比较简单的就是2维单通道
    int sz[] = {10,10};
    SparseMat sm(2,sz,CV_32FC1);
    for (int i = 0;i <10 ; ++i){ // 100个元素只赋予10个
        int coordinate[2];
        coordinate[0] = sz[0] * rand();
        coordinate[1] = sz[1] * rand();
        sm.ref<float>(coordinate) += 1.0f;
    }

    // 一个例子
    const int dims = 5;
    int size[5] = { 10, 10, 10, 10, 10 };
    SparseMat sparse_mat(dims, size, CV_32F);
    for (int i = 0; i < 1000; i++) // 共1000*100个元素,只赋值1000个元素
    {
        int idx[dims]; // 作为const int * idx传入ref的参数,也就是坐标向量(x,y,z,u,v)
        for (int k = 0; k < dims; k++) 
            idx[k] = rand() % size[k]; // 随机的赋值,每个维度随机分配一个值,共5个值作为坐标向量
        sparse_mat.ref<float>(idx) += 1.f; // 这个坐标被赋值1.0f,如果重复遇见该坐标再加1.0f
    }
    cout << "nnz = " << sparse_mat.nzcount() << endl; // 计算非0元素,991个,说明有9个元素是重复的

    // 使用迭代器获取稀疏矩阵的非0元素
    /*
        运行这个循环,元素并没有按逻辑顺序（字典等）枚举
        它们的顺序与存储在哈希表中的顺序相同（半随机）
        可以收集指向节点的指针,并对它们进行排序,以获得正确的顺序
        但是注意当向矩阵中添加更多元素时,指向节点的指针可能会变得无效
        这可能是由于可能的缓冲区重新分配造成的
    */
    SparseMatConstIterator_<float> it = sparse_mat.begin<float>();
    SparseMatConstIterator_<float> it_end = sparse_mat.end<float>();
    double s = 0; // 用于求和
    int dims_ = sparse_mat.dims(); //
    cout << "dims_ = " << dims_ << endl; // 5
    // 观察确实可以知道有9个点值是2
    for (; it != it_end; ++it)
    {
        // 利用node方法获取这个坐标点,因为坐标点是5个值所以是Node*
        const SparseMat::Node* n = it.node(); 
        printf("(");
        for (int i = 0; i < dims_; i++) // 遍历坐标点的每个坐标,也就是索引值
             // 调用链为SparseMatConstIterator_->node->idx[dim]获取坐标
            printf("%d%s", n->idx[i], i < dims_ - 1 ? ", " : ")");// dim=0,1,2,3时打印',',4打印')'
        printf(": %g\n", it.value<float>()); // SparseMatConstIterator_->node->value<float>(),获取该坐标点的值
        s += *it; // 求和
    }
    printf("Element sum is %g\n", s); // 1000

    /*
        当需要同时处理2个或更多稀疏矩阵时,可以使用上述两种方法的组合
        例如,下方函数是如何计算2个浮点稀疏矩阵的非标准化互相关
    */
    // 两个用于测试计算互相关系数的简单二维单通道稀疏矩阵
    // SparseMat(int dims, const int* _sizes, int _type);
    int dims_a = 2,dims_b = 2;
    const int * sizes_a = new int[dims_a]{ 2, 2 };
    const int * sizes_b = new int[dims_b]{ 2, 2 };
    SparseMat a(dims_a, sizes_a, CV_32FC1), b(dims_b, sizes_b, CV_32FC1);
    // 分别赋予4个初值
    a.ref<float>(0, 0) = 1.0f;a.ref<float>(0, 1) = 2.0f;
    a.ref<float>(1, 0) = 3.0f;a.ref<float>(1, 1) = 4.0f;
    b.ref<float>(0, 0) = 5.0f;b.ref<float>(0, 1) = 6.0f;
    b.ref<float>(1, 0) = 7.0f;b.ref<float>(1, 1) = 8.0f;
    // 计算互相关系数
    double corr = cross_corr(a, b);
    cout << "corr = " << corr << endl; // 70 = 1*5 + 2*6 + 3*7 + 4*8
    return 0;
}