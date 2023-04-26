pipeline {
    agent 
    {
        label "docker"
    }
    enviroment
    {
        
    }
    stages 
    {
        stage('Build') 
        {
            steps 
            {
                script
                {
                    sh "docker build -t ContBuild:latest -f /deploy/Dockerfile"
                }
            }
            post 
            {
                failure 
                {
                    // send email notification on failure
                    emailext body: "The 'build' stage has failed. Please check the build logs for more details.",
                        subject: "Pipeline failure",
                        to: "lordaleks2001WoW@gmail.com"
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
                    sh "docker build -t ContTest:latest -f /deploy/Dockerfile.second"
                }
            }
            post 
            {
                failure 
                {
                    // send email notification on failure
                    emailext body: "The 'test' stage has failed. Please check the build logs for more details.",
                        subject: "Pipeline failure",
                        to: "lordaleks2001WoW@gmail.com"
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
                    sh "docker build -t ContDeploy:1.0 -f /deploy/Dockerfile.third"
                }
            }
        }

        stage('Publish') {
            agent any
            steps 
            {
                archiveArtifacts artifacts: '*.tar', allowEmptyArchive: true
            }
        }
    }
}
