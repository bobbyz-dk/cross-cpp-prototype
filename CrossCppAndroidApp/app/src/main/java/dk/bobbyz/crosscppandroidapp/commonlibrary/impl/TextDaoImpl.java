package dk.bobbyz.crosscppandroidapp.commonlibrary.impl;

import android.content.Context;
import android.os.Environment;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.List;

import dk.bobbyz.crosscppandroidapp.commonlibrary.TextDao;
import dk.bobbyz.crosscppandroidapp.commonlibrary.model.Text;

/**
 * Created by Bobby on 23-05-2015.
 */
public class TextDaoImpl implements TextDao{

    private long nativeHandle;
    private Context context;
    private String dbPath;

    public TextDaoImpl(Context context, String dbPath) {
        this.context = context;
        nativeHandle = this.initTextDao(dbPath);
        this.dbPath = dbPath;
    }

    // declare native methods
    public native long initTextDao(String dbPath);
    public native void destructTextDao();
    public native List<Text> findAll();
    public native void insert(Text text);
    // load library that contains static method
    static {
        System.loadLibrary("CommonLibrary");
    }

    private boolean doesDatabaseExist(String dbName) {
        File dbFile = context.getDatabasePath(dbName);
        return dbFile.exists();
    }

    private void copyDataBase() throws IOException {

        String DB_NAME = "TextDB.db";
        String dataDir = Environment.getDataDirectory().toString();
        String path = String.format("%s/CrossCppAndroidApp/databases/%s", dataDir, DB_NAME);

        if (!doesDatabaseExist(path)) {
            InputStream myInput = context.getAssets().open(DB_NAME);

            OutputStream myOutput = new FileOutputStream(path);

            byte[] buffer = new byte[1024];
            int length;
            while ((length = myInput.read(buffer)) > 0) {
                myOutput.write(buffer, 0, length);
            }

            //Close the streams
            myOutput.flush();
            myOutput.close();
            myInput.close();
        }
    }
}
