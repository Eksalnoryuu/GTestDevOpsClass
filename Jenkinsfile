pipeline {
    agent any

    stages {
        stage('Build') 
        {
            steps 
            {
                script
                {
                    try
                    {
                    def contBuild = docker.image("kost13/cpp-gtest:gtest-v1.10-v1.1").rename("contBuild").inside("-u root")
                    {
                        sh "cd /home"
                        sh "git clone https://github.com/Eksalnoryuu/GTestDevOpsClass.git"
                        sh "cd /home/GTestDevOpsClass"
                        sh "git clone https://github.com/google/googletest.git"
                        sh "mkdir build"
                        sh "cd/home/GTestDevOpsClass/build"
                        sh "cmake .."
                        sh "make"
                    }
                    }
                    finally
                    {

                    }
                }
            }
            post 
            {
                failure 
                {
                    // send email notification on failure
                    emailext body: "The 'build' stage has failed. Please check the build logs for more details.",
                        subject: "Pipeline failure",
                        to: "ameysztowicz@student.agh.edu.pl"m"
                }
            }
        }

        stage('Test') 
        {
            agent any
            steps 
            {
                script
                {
                    def contTest = contBuild.newImage("contTest")
                    try 
                    {
                        contTest.inside("-u root")
                        {
                            sh "cd /home/GTestDevOpsClass/Build"
                            sh "./mytests"
                        }
                    }
                    finally
                    {

                    }
                }
            }
            post 
            {
                failure 
                {
                    // send email notification on failure
                    emailext body: "The 'test' stage has failed. Please check the build logs for more details.",
                        subject: "Pipeline failure",
                        to: "ameysztowicz@student.agh.edu.pl"
                }
            }
        }

        stage('Deploy') 
        {
            agent any
            steps 
            {
                script
                {
                    def contDeploy = contTest.newImage("ContDeploy")
                    contDeploy.inside("-u root")
                    {
                        sh "cd /home"
                        sh "cp cd /home/GTestDevOpsClass/build/main /home "
                        sh "rm -rf GTestDevOpsClass "
                    }
                }
            }
        }

        stage('Publish') {
            agent any
            steps 
            {
                script
                {
                contDeploy.rename("ContCPP")
                }
                archiveArtifacts artifacts: '*.tar', allowEmptyArchive: true
            }
        }
    }
}
