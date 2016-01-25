#include <phpcpp.h>
#include <iostream>
#include <HMMlib/hmm_table.hpp>
#include <HMMlib/hmm_vector.hpp>
#include <HMMlib/hmm.hpp>

void testHMM()
{
    int K = 2; // number of states
    int M = 2; // alphabet size
    int n = 4; // length of observed sequence

    boost::shared_ptr<hmmlib::HMMVector<double> > pi_ptr(new hmmlib::HMMVector<double>(K));
    boost::shared_ptr<hmmlib::HMMMatrix<double> > T_ptr(new hmmlib::HMMMatrix<double>(K,K));
    boost::shared_ptr<hmmlib::HMMMatrix<double> > E_ptr(new hmmlib::HMMMatrix<double>(M, K));
	
    hmmlib::HMMVector<double> &pi = *pi_ptr;
    // initial probabilities
    pi(0)  = 0.2; pi(1) = 0.8;

    hmmlib::HMMMatrix<double> &T = *T_ptr;
    // transitions from state 0
    T(0,0) = 0.1; T(0,1) = 0.9;
    // transitions from state 1
    T(1,0) = 0.9; T(1,1) = 0.1;

    hmmlib::HMMMatrix<double> &E = *E_ptr;
    // emissions from state 0
    E(0,0) = 0.25; E(1,0) = 0.75;
    // emissions from state 1
    E(0,1) = 0.75; E(1,1) = 0.25;

    Php::out << "Constructing HMM" << "</br>" << std::endl;
    hmmlib::HMM<double> hmm(pi_ptr, T_ptr, E_ptr);

    Php::out << "obs : [0, 1, 0, 1]" << "</br>" << std::endl;
    sequence obs(n);
    obs[0] = 0;  
    obs[1] = 1;
    obs[2] = 0;
    obs[3] = 1;
    Php::out << "obs length: " << obs.size() << "</br>" << std::endl;

    Php::out << "Running viterbi" << "</br>" << std::endl;
    sequence hiddenseq(n);
    double loglik = hmm.viterbi(obs, hiddenseq);
    Php::out << "-- hiddenseq: [" << hiddenseq[0] << ", " << hiddenseq[1] << ", " << hiddenseq[2] << ", " << hiddenseq[3] << "]" << "</br>" << std::endl;
    Php::out << "-- log likelihood of hiddenseq: " << loglik << "</br>" << std::endl;

    Php::out << "Running forward" << "</br>" << std::endl;
    hmmlib::HMMMatrix<double> F(n, K);
    hmmlib::HMMVector<double> scales(n);
    hmm.forward(obs, scales, F);

    Php::out << "Running likelihood" << "</br>" << std::endl;
    loglik = hmm.likelihood(scales);
    Php::out << "-- loglikelihood of obs: " << loglik << "</br>" << std::endl;

    Php::out << "Running backward" << "</br>" << std::endl;
    hmmlib::HMMMatrix<double> B(n, K);
    hmm.backward(obs, scales, B);

    Php::out << "Running posterior decoding" << "</br>" << std::endl;
    hmmlib::HMMMatrix<double> pd(n, K);
    hmm.posterior_decoding(obs, F, B, scales, pd);

    Php::out << "Running Baum-Welch" << "</br>" << std::endl;
    boost::shared_ptr<hmmlib::HMMVector<double> > pi_counts_ptr(new hmmlib::HMMVector<double>(K));
    boost::shared_ptr<hmmlib::HMMMatrix<double> > T_counts_ptr(new hmmlib::HMMMatrix<double>(K,K));
    boost::shared_ptr<hmmlib::HMMMatrix<double> > E_counts_ptr(new hmmlib::HMMMatrix<double>(M,K));
    hmm.baum_welch(obs, F, B, scales, *pi_counts_ptr, *T_counts_ptr, *E_counts_ptr);

    Php::out << "Constructing new HMM" << "</br>" << std::endl;
    hmmlib::HMM<double> hmm2(pi_counts_ptr, T_counts_ptr, E_counts_ptr);

    Php::out << "Running forward on new HMM" << "</br>" << std::endl;
    hmm2.forward(obs, scales, F);
    Php::out << "Running likelihood on new HMM" << "</br>" << std::endl;
    loglik = hmm2.likelihood(scales);
    Php::out << "-- loglikelihood of obs in new HMM: " << loglik << "</br>" << std::endl;
}

/**
 *  tell the compiler that the get_module is a pure C function
 */
extern "C" {
    
    /**
     *  Function that is called by PHP right after the PHP process
     *  has started, and that returns an address of an internal PHP
     *  strucure with all the details and features of your extension
     *
     *  @return void*   a pointer to an address that is understood by PHP
     */
    PHPCPP_EXPORT void *get_module() 
    {
        // static(!) Php::Extension object that should stay in memory
        // for the entire duration of the process (that's why it's static)
        static Php::Extension extension("HMM", "1.0");
                
        extension.add("testHMM", testHMM);
        
        // return the extension
        return extension;
    }
}
