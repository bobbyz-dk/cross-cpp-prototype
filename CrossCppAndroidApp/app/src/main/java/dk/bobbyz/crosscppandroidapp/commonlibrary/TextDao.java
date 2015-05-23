package dk.bobbyz.crosscppandroidapp.commonlibrary;

import java.util.List;

import dk.bobbyz.crosscppandroidapp.commonlibrary.model.Text;

/**
 * Created by Bobby on 23-05-2015.
 */
public interface TextDao {
    List<Text> findAll();

    void insert(Text text);
}
