#include <string>
#include <vector>

class SelfVanHoveCorrelationFunction
{
public:
    SelfVanHoveCorrelationFunction();
    virtual ~SelfVanHoveCorrelationFunction();

    void read_commands(int argc, char* argv[]);
    void read_input_file();
    void initialize_rest_members();
    void compute_gs_rt();
    void write_output_file();

protected:
    bool print_headline_;
    bool is_trajectory_wrapped_;

    unsigned int dimension_;
    unsigned int calculation_dimension_;
    unsigned int start_frame_;
    unsigned int interval_;
    unsigned int number_of_timepoints_;
    unsigned int number_of_frames_to_be_averaged_;
    unsigned int number_of_bins_;
    unsigned int number_of_layers_;
    unsigned int output_precision_;
    unsigned int number_of_atoms_;
    unsigned int number_of_types_of_atoms_;
    unsigned int number_of_frames_;

    double frame_interval_time_;
    double cutoff_distance_;
    double bin_width_;
    double layer_left_point_;
    double layer_right_point_;
    double layer_width_;

    std::string input_file_name_;
    std::string trajectory_file_name_;
    std::string output_file_name_;

    std::vector< unsigned int > atom_type_;                                                  // [atom]
    std::vector< std::vector< int > > atom_layer_;                                           // [frame][atom]
    std::vector< std::vector< std::vector < double > > > atom_coordinates_;                  // [frame][atom][dimension]
    std::vector< std::vector< std::vector < std::vector < double > > > > gs_rt_;             // [layer][timepoint][bin][type]

private:
};